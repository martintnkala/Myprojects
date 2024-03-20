SET SERVEROUTPUT ON SIZE UNLIMITED;

DROP FUNCTION IF EXISTS cast_strings;
DROP TYPE IF EXISTS structs;
DROP TYPE IF EXISTS struct;
DROP TYPE IF EXISTS tre;
DROP TYPE IF EXISTS my_record_type;



CREATE OR REPLACE TYPE tre IS TABLE OF VARCHAR2(20);
/

CREATE OR REPLACE TYPE struct IS OBJECT
(
  xnumber NUMBER,
  xdate   DATE,
  xstring VARCHAR2(20)
);
/

CREATE OR REPLACE TYPE structs IS TABLE OF struct;
/

CREATE OR REPLACE TYPE my_record_type AS OBJECT (
  my_number NUMBER,
  my_date   DATE,
  my_string VARCHAR2(20)
);

CREATE OR REPLACE TYPE my_record_table_type AS TABLE OF my_record_type;

CREATE OR REPLACE FUNCTION cast_strings(
  p_string_list my_record_table_type
) RETURN my_record_table_type IS
  v_result my_record_table_type := my_record_table_type();
BEGIN
  FOR i IN 1..p_string_list.COUNT LOOP
    -- Assuming the input string format is 'number,date,string'

    DECLARE
      v_number NUMBER;
      v_date   DATE;
      v_string VARCHAR2(20);
    BEGIN
      -- Split the input string into components
      SELECT TO_NUMBER(REGEXP_SUBSTR(p_string_list(i), '[^,]+', 1, 1)) INTO v_number FROM DUAL;
      SELECT TO_DATE(REGEXP_SUBSTR(p_string_list(i), '[^,]+', 1, 2), 'YYYY-MM-DD') INTO v_date FROM DUAL;
      SELECT REGEXP_SUBSTR(p_string_list(i), '[^,]+', 1, 3) INTO v_string FROM DUAL;

      -- Create a record and add it to the result
      v_result.EXTEND;
      v_result(i) := my_record_type(v_number, v_date, v_string);
    EXCEPTION
      WHEN OTHERS THEN
        NULL;
    END;
  END LOOP;

  RETURN v_result;
END cast_strings;
/


CREATE OR REPLACE FUNCTION verify_date(pv_date_in VARCHAR2) RETURN BOOLEAN IS
  lv_date_in VARCHAR2(11);
  lv_date BOOLEAN := FALSE;
BEGIN
  lv_date_in := UPPER(pv_date_in);

  IF REGEXP_LIKE(lv_date_in, '^[0-9]{2,2}-[ADFJMNOS][ACEOPU][BCGLNPRTVY]-([0-9]{2,2}|[0-9]{4,4})$') THEN
    CASE
      WHEN SUBSTR(lv_date_in, 4, 3) IN ('JAN', 'MAR', 'MAY', 'JUL', 'AUG', 'OCT', 'DEC') AND
           TO_NUMBER(SUBSTR(pv_date_in, 1, 2)) BETWEEN 1 AND 31 THEN
        lv_date := TRUE;
      WHEN SUBSTR(lv_date_in, 4, 3) IN ('APR', 'JUN', 'SEP', 'NOV') AND
           TO_NUMBER(SUBSTR(pv_date_in, 1, 2)) BETWEEN 1 AND 30 THEN
        lv_date := TRUE;
      WHEN SUBSTR(lv_date_in, 4, 3) = 'FEB' THEN
        IF (LENGTH(pv_date_in) = 9 AND MOD(TO_NUMBER(SUBSTR(pv_date_in, 8, 2)) + 2000, 4) = 0 OR
            LENGTH(pv_date_in) = 11 AND MOD(TO_NUMBER(SUBSTR(pv_date_in, 8, 4)), 4) = 0) AND
           TO_NUMBER(SUBSTR(pv_date_in, 1, 2)) BETWEEN 1 AND 29 THEN
          lv_date := TRUE;
        ELSE
          IF TO_NUMBER(SUBSTR(pv_date_in, 1, 2)) BETWEEN 1 AND 28 THEN
            lv_date := TRUE;
          END IF;
        END IF;
      ELSE
        NULL;
    END CASE;
  END IF;

  RETURN lv_date;

EXCEPTION
  WHEN VALUE_ERROR THEN
    RETURN lv_date;
END;
/

DECLARE
  /* Test set values. */
  TYPE test_case IS TABLE OF VARCHAR2(11);
  
  /* Test set values. */
  lv_test_case  TEST_CASE := test_case('15-JAN-2022','32-JAN-2022','29-FEB-2022','29-FEB-2024');
BEGIN
  /* Test the set of values. */
  FOR i IN 1..lv_test_case.COUNT LOOP
    IF verify_date(lv_test_case(i)) THEN
  	  dbms_output.put_line('True.');
    ELSE
      dbms_output.put_line('False.');
    END IF;
  END LOOP;
END;
/



CREATE OR REPLACE FUNCTION cast_strings
( pv_list TRE ) RETURN struct IS
  lv_retval STRUCT := struct(xnumber =>NULL 
                             ,xdate => NULL
                             ,xstring => NULL);

  FUNCTION debugger(pv_string VARCHAR2) RETURN VARCHAR2 IS
    lv_retval VARCHAR2(60);
  BEGIN
    $IF $$DEBUG = 1 $THEN
      lv_retval := 'Evaluating [' || pv_string || ']';
    $ELSE
      lv_retval := NULL;
    $END
    
    RETURN lv_retval;
  END debugger;

BEGIN
  FOR i IN 1..pv_list.LAST LOOP
    dbms_output.put_line(debugger(pv_list(i)));

    IF pv_list.EXISTS(i) THEN
      CASE
        WHEN REGEXP_LIKE(pv_list(i), '^\d+$') THEN
          lv_retval.xnumber := TO_NUMBER(pv_list(i));

        WHEN verify_date(pv_list(i)) THEN
          lv_retval.xdate := TO_DATE(pv_list(i), 'DD-MON-RR');

        WHEN REGEXP_LIKE(pv_list(i), '^[[:alnum:][:punct:][:space:]]+$') THEN
          lv_retval.xstring := pv_list(i);


        ELSE
          NULL;
      END CASE;
    END IF;
  END LOOP;

  RETURN lv_retval;
END;
/

DECLARE
  /* Define a list. */
  lv_list  TRE := TRE('16-APR-2018', 'Day after ...', '1040');
  
  /* Declare a structure. */
  lv_struct  STRUCT := struct(NULL, NULL, NULL); 
BEGIN
  /* Assign a parsed value set to get a value structure. */
  lv_struct := cast_strings(lv_list);
  
  /* Print the values of the compound struct variable. */
  dbms_output.put_line('xstring [' || lv_struct.xstring|| ']');
  dbms_output.put_line('xdate   [' || TO_CHAR(lv_struct.xdate, 'DD-MON-YYYY') || ']');
  dbms_output.put_line('xnumber [' || TO_CHAR(lv_struct.xnumber) || ']');
END;
/


SELECT TO_CHAR(xdate,'DD-MON-YYYY') AS xdate
,      xnumber
,      xstring
FROM   TABLE(structs(cast_strings(tre('catch22','25','25-Nov-1945'))
                    ,cast_strings(tre('31-APR-2017','1918','areodromes')))); 


