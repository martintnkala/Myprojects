/* Unconditionally drop function. */
DROP FUNCTION IF EXISTS verify_date;
 
 
CREATE FUNCTION verify_date
  ( IN pv_date_in  VARCHAR(10)) RETURNS BOOLEAN AS
  $$
  DECLARE
    lv_retval  BOOLEAN := FALSE;
  BEGIN
    IF REGEXP_MATCH(pv_date_in,'^[0-9]{2,4}-[0-9]{2,2}-[0-9]{2,2}$') IS NOT NULL THEN
      CASE
        WHEN (LENGTH(pv_date_in) = 10 AND
              SUBSTRING(pv_date_in,6,2) IN ('01','03','05','07','08','10','12') AND
              TO_NUMBER(SUBSTRING(pv_date_in,9,2),'99') BETWEEN 1 AND 31) OR
             (LENGTH(pv_date_in) = 8 AND
              SUBSTRING(pv_date_in,4,2) IN ('01','03','05','07','08','10','12') AND
              TO_NUMBER(SUBSTRING(pv_date_in,7,2),'99') BETWEEN 1 AND 31) THEN 
          lv_retval := true;

        WHEN (LENGTH(pv_date_in) = 10 AND
              SUBSTRING(pv_date_in,6,2) IN ('04','06','09','11') AND
              TO_NUMBER(SUBSTRING(pv_date_in,9,2),'99') BETWEEN 1 AND 30) OR
             (LENGTH(pv_date_in) = 8 AND
              SUBSTRING(pv_date_in,4,2) IN ('04','06','09','11') AND
              TO_NUMBER(SUBSTRING(pv_date_in,7,2),'99') BETWEEN 1 AND 30) THEN 
          lv_retval := true;

        WHEN (LENGTH(pv_date_in) = 10 AND SUBSTRING(pv_date_in,6,2) = '02') OR
             (LENGTH(pv_date_in) =  8 AND SUBSTRING(pv_date_in,4,2) = '02') THEN
          IF (LENGTH(pv_date_in) = 10 AND
              MOD(TO_NUMBER(SUBSTRING(pv_date_in,1,4),'9999'),4) = 0) OR
             (LENGTH(pv_date_in) =  8 AND
              MOD(TO_NUMBER(CONCAT('20',SUBSTRING(pv_date_in,1,2)),'9999'),4) = 0) THEN
            IF TO_NUMBER(SUBSTRING(pv_date_in,(LENGTH(pv_date_in) -1),2),'99')
   			     BETWEEN 1 AND 29 THEN
			  lv_retval := true;
			END IF;
          ELSE 
            IF TO_NUMBER(SUBSTRING(pv_date_in,(LENGTH(pv_date_in) -1),2),'99')
   			     BETWEEN 1 AND 28 THEN
              lv_retval := true;
			-- ELSE
			--   RAISE NOTICE '[% %]','Not a non-leap year day:',
			--                         SUBSTRING(pv_date_in,(LENGTH(pv_date_in) - 1),2);
            END IF;
          END IF;
		ELSE
          NULL;
      END CASE;
    END IF;

    RETURN lv_retval;
  END;
$$ LANGUAGE plpgsql;
 
 
DO
$$
DECLARE
 
  lv_test_case  VARCHAR[] := ARRAY['2022-01-15','2022-01-32','22-02-29','2022-02-29','2024-02-29'];
BEGIN
  FOR i IN 1..ARRAY_LENGTH(lv_test_case,1) LOOP
    IF verify_date(lv_test_case[i]) = 't' THEN
  	  RAISE NOTICE '[%][%]','True. ',lv_test_case[i];
    ELSE
  	  RAISE NOTICE '[%][%]','False.',lv_test_case[i];
    END IF;
  END LOOP;
END;
$$;
 
/* Unconditionally drop function. */
DROP FUNCTION cast_strings;
 
/* Unconditionally drop TYPE. */
DROP TYPE IF EXISTS struct;
 
 
CREATE TYPE struct AS
( xnumber  DECIMAL
, xdate    DATE
, xstring  VARCHAR(20));
 
 
CREATE OR REPLACE
  FUNCTION cast_strings
  ( pv_list  VARCHAR[] ) RETURNS struct AS
  $$
  DECLARE
    lv_retval struct;	
  BEGIN  
    FOR i IN 1..ARRAY_LENGTH(pv_list,1) LOOP
      CASE	
        WHEN pv_list[i] SIMILAR TO '[0-9]*' THEN
          lv_retval.xnumber := pv_list[i];
 
       
        WHEN pv_list[i] SIMILAR TO '[0-9-]*' AND verify_date(pv_list[i]) THEN
          lv_retval.xdate := TO_DATE(pv_list[i],'YYY-MM-DD');
 
        
        WHEN pv_list[i] SIMILAR TO '[0-9A-Za-z\-\.\ ]*' THEN
          lv_retval.xstring := pv_list[i];
        ELSE
      END CASE;
    END LOOP;

    RETURN lv_retval;
  END;
$$ LANGUAGE plpgsql;
 
DO
$$
DECLARE
 
  lv_list  VARCHAR[] := ARRAY['2018-04-16','Day after ...','1040'];

  lv_struct  struct; 
BEGIN
  lv_struct := cast_strings(lv_list);

  RAISE NOTICE '[%]',lv_struct.xstring;
  RAISE NOTICE '[%]',TO_CHAR(lv_struct.xdate,'DD-MON-YYYY');
  RAISE NOTICE '[%]',lv_struct.xnumber;
END;
$$;

DO
$$
DECLARE
  lv_list    VARCHAR(11)[] := ARRAY['86','1944-04-25','Happy'];
  lv_struct  STRUCT;
BEGIN
  /* Pass the array of strings and return a record type. */
  lv_struct := cast_strings(lv_list);
 
  /* Print the elements returned. */
  RAISE NOTICE '[%]', lv_struct.xnumber;
  RAISE NOTICE '[%]', lv_struct.xdate;
  RAISE NOTICE '[%]', lv_struct.xstring;
END;
$$;
 
 WITH get_struct AS
(SELECT cast_strings(ARRAY['99','2015-06-14','Agent 99']) AS mystruct)
SELECT (mystruct).xnumber
,      (mystruct).xdate
,      (mystruct).xstring
FROM    get_struct;



