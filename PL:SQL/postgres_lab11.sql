DROP PROCEDURE IF EXISTS contact_insert
( IN pv_member_type         VARCHAR(30)
, IN pv_account_number      VARCHAR(10)
, IN pv_credit_card_number  VARCHAR(19)
, IN pv_credit_card_type    VARCHAR(30)
, IN pv_first_name          VARCHAR(20)
, IN pv_middle_name         VARCHAR(20)
, IN pv_last_name           VARCHAR(20)
, IN pv_contact_type        VARCHAR(30)
, IN pv_address_type        VARCHAR(30)
, IN pv_city                VARCHAR(30)
, IN pv_state_province      VARCHAR(30)
, IN pv_postal_code         VARCHAR(20)
, IN pv_street_address      VARCHAR(30)
, IN pv_telephone_type      VARCHAR(30)
, IN pv_country_code        VARCHAR(3)
, IN pv_area_code           VARCHAR(6)
, IN pv_telephone_number    VARCHAR(10)
, IN pv_created_by          INTEGER
, IN pv_last_updated_by     INTEGER);


DROP PROCEDURE IF EXISTS contact_insert
( IN pv_member_type         VARCHAR(30)
, IN pv_account_number      VARCHAR(10)
, IN pv_credit_card_number  VARCHAR(19)
, IN pv_credit_card_type    VARCHAR(30)
, IN pv_first_name          VARCHAR(20)
, IN pv_middle_name         VARCHAR(20)
, IN pv_last_name           VARCHAR(20)
, IN pv_contact_type        VARCHAR(30)
, IN pv_address_type        VARCHAR(30)
, IN pv_city                VARCHAR(30)
, IN pv_state_province      VARCHAR(30)
, IN pv_postal_code         VARCHAR(20)
, IN pv_street_address      VARCHAR(30)
, IN pv_telephone_type      VARCHAR(30)
, IN pv_country_code        VARCHAR(3)
, IN pv_area_code           VARCHAR(6)
, IN pv_telephone_number    VARCHAR(10)
, IN pv_user_name           VARCHAR(20));


/* Create or replace get_member_id function. */
CREATE OR REPLACE
  FUNCTION get_member_id
  ( IN pv_account_number  VARCHAR ) RETURNS INTEGER AS
$$
  /* Required for PL/pgSQL programs. */
  DECLARE
  
    /* Local return variable. */
    lv_retval  INTEGER := 0;  -- Default value is 0.
 
    /* Use a cursor, which will not raise an exception at runtime. */
    find_member_id CURSOR 
    ( cv_account_number  VARCHAR ) FOR
      SELECT m.member_id
	  FROM   member m
	  WHERE  m.account_number = cv_account_number;
 
  BEGIN  
 
    /* Assign a value when a row exists. */
    FOR i IN find_member_id(pv_account_number) LOOP
      lv_retval := i.member_id;
    END LOOP;
 
    /* Return 0 when no row found and the ID # when row found. */
    RETURN lv_retval;
  END;
$$ LANGUAGE plpgsql;

SELECT  retval AS "Return Member Value"
FROM   (SELECT get_member_id(m.account_number) AS retval
        FROM   member m
        ORDER BY m.account_number LIMIT 1) x
ORDER BY 1;


CREATE OR REPLACE
  FUNCTION get_lookup_id
  ( IN pv_table_name   VARCHAR
  , IN pv_column_name  VARCHAR
  , IN pv_lookup_type  VARCHAR ) RETURNS INTEGER AS
$$
  /* Required for PL/pgSQL programs. */
  DECLARE
    /* Local return variable. */
    lv_retval  INTEGER := 0;  -- Default value is 0.
 
    /* Use a cursor, which will not raise an exception at runtime. */
    find_lookup_id CURSOR 
    ( cv_table_name   VARCHAR
    , cv_column_name  VARCHAR
    , cv_lookup_type  VARCHAR ) FOR
     SELECT common_lookup_id
     FROM common_lookup
     WHERE common_lookup_column = cv_column_name
      AND common_lookup_type = cv_lookup_type;
  BEGIN  
    /* Assign a value when a row exists. */
    FOR i IN find_lookup_id( pv_table_name
                           , pv_column_name
                           , pv_lookup_type ) LOOP
      lv_retval := i.common_lookup_id;
    END LOOP;
	
    /* Return 0 when no row found and the ID # when row found. */
    RETURN lv_retval;
  END;
$$ LANGUAGE plpgsql;


/* Test the get_lookup_id function. */
SELECT    DISTINCT
          CASE
            WHEN NOT retval = 0 THEN retval
          END AS "Return Lookup Value"
FROM     (SELECT get_lookup_id('MEMBER', 'MEMBER_TYPE', cl.common_lookup_type) AS retval
          FROM   common_lookup cl) x
WHERE NOT retval = 0
ORDER BY  1;

CREATE OR REPLACE
  FUNCTION get_system_user_id
  ( IN pv_user_name  VARCHAR ) RETURNS INTEGER AS
$$
  /* Required for PL/pgSQL programs. */
  DECLARE
    /* Local return variable. */
    lv_retval  INTEGER := 0;  -- Default value is 0.
 
    /* Use a cursor, which will not raise an exception at runtime. */
    find_system_user_id CURSOR 
    ( cv_user_name  VARCHAR ) FOR
      SELECT su.system_user_id
      FROM system_user su
      WHERE su.system_user_name = cv_user_name;
  BEGIN  
    /* Assign a value when a row exists. */
    FOR i IN find_system_user_id(pv_user_name) LOOP
      lv_retval := i.system_user_id;
    END LOOP;
 
    /* Return 0 when no row found and the ID # when row found. */
    RETURN lv_retval;
  END;
$$ LANGUAGE plpgsql;

/* Test the get_system_user_id function. */
SELECT  retval AS "Return System Value"
FROM   (SELECT get_system_user_id(su.system_user_name) AS retval
        FROM   system_user su
        WHERE  system_user_name LIKE 'DBA%'	LIMIT 5) x
ORDER BY 1;

-- Transaction Management Solution modified from Lab 9.
SELECT 'Create contact_insert procedure' AS "Statement";
CREATE OR REPLACE PROCEDURE contact_insert
( IN pv_member_type         VARCHAR(30)
, IN pv_account_number      VARCHAR(10)
, IN pv_credit_card_number  VARCHAR(19)
, IN pv_credit_card_type    VARCHAR(30)
, IN pv_first_name          VARCHAR(20)
, IN pv_middle_name         VARCHAR(20)
, IN pv_last_name           VARCHAR(20)
, IN pv_contact_type        VARCHAR(30)
, IN pv_address_type        VARCHAR(30)
, IN pv_city                VARCHAR(30)
, IN pv_state_province      VARCHAR(30)
, IN pv_postal_code         VARCHAR(20)
, IN pv_street_address      VARCHAR(30)
, IN pv_telephone_type      VARCHAR(30)
, IN pv_country_code        VARCHAR(3)
, IN pv_area_code           VARCHAR(6)
, IN pv_telephone_number    VARCHAR(10)
, IN pv_system_user_id      INTEGER) AS
$$
DECLARE
  /* Declare type variables. */
  lv_member_type       INTEGER;
  lv_credit_card_type  INTEGER;
  lv_contact_type      INTEGER;
  lv_address_type      INTEGER;
  lv_telephone_type    INTEGER;
  
  /* Local surrogate key variables. */
  lv_member_id          INTEGER;
  lv_contact_id         INTEGER;
  lv_address_id         INTEGER;
  lv_street_address_id  INTEGER;
  
  /* Declare local variable. */
  lv_middle_name  VARCHAR(20);

  /* Declare error handling variables. */
  err_num  TEXT;
  err_msg  INTEGER;
BEGIN

  /* Assing a null value to an empty string. */ 
  IF pv_middle_name IS NULL THEN
    lv_middle_name = '';
  END IF;
  
  /*
   *  Replace the character type values with their appropriate
   *  common_lookup_id values by calling the get_lookup_id
   *  function.
   */
  lv_member_type := get_lookup_id('MEMBER','MEMBER_TYPE',pv_member_type);
  lv_credit_card_type := get_lookup_id('MEMBER', 'CREDIT_CARD_TYPE', pv_credit_card_type);
  lv_contact_type := get_lookup_id('CONTACT', 'CONTACT_TYPE', pv_contact_type);
  lv_address_type := get_lookup_id('ADDRESS', 'ADDRESS_TYPE', pv_address_type);
  lv_telephone_type := get_lookup_id('TELEPHONE', 'TELEPHONE_TYPE', pv_telephone_type);

  /*
   *  Check for existing member row. Assign value when one exists,
   *  and assign zero when no member row is found.
   */
  lv_member_id := get_member_id(pv_account_number);

  /*
   *  Enclose the insert into member in an if-statement.
   */
   IF lv_member_id = 0 THEN
    /*
     *  Insert into the member table when no row is found.
     *
     *  Replace the two subqueries by calling the get_lookup_id
     *  function for either the pv_member_type or credit_card_type
     *  value and assign it to a local variable.
     */
    INSERT INTO member
    ( member_type
    , account_number
    , credit_card_number
    , credit_card_type
    , created_by
    , last_updated_by )
    VALUES
    ( lv_member_type
    , pv_account_number
    , pv_credit_card_number
    , lv_credit_card_type
    , pv_system_user_id
    , pv_system_user_id )
    RETURNING member_id INTO lv_member_id;
  END IF;

  /*
   *  Insert into the member table when no row is found.
   *
   *  Replace the subquery by calling the get_lookup_id
   *  function for the pv_contact_type value and
   *  assign it to a local variable.
   */
  INSERT INTO contact
  ( member_id
  , contact_type
  , first_name
  , middle_name
  , last_name
  , created_by
  , last_updated_by )
  VALUES
  ( lv_member_id
  , lv_contact_type
  , pv_first_name
  , pv_middle_name
  , pv_last_name
  , pv_system_user_id
  , pv_system_user_id )
  RETURNING contact_id INTO lv_contact_id;

  /*
   *  Insert into the member table when no row is found.
   *
   *  Replace the subquery by calling the get_lookup_id
   *  function for the pv_address_type value and
   *  assign it to a local variable.
   */
  INSERT INTO address
  ( contact_id
  , address_type
  , city
  , state_province
  , postal_code
  , created_by
  , last_updated_by )
  VALUES
  ( lv_contact_id
  , lv_address_type
  , pv_city
  , pv_state_province
  , pv_postal_code
  , pv_system_user_id
  , pv_system_user_id )
  RETURNING address_id INTO lv_address_id;

  /*
   *  Insert into the member table when no row is found.
   */
  INSERT INTO street_address
  ( address_id
  , street_address
  , created_by
  , last_updated_by )
  VALUES
  ( lv_address_id
  , pv_street_address
  , pv_system_user_id
  , pv_system_user_id )
  RETURNING street_address_id INTO lv_street_address_id;

  /*
   *  Insert into the member table when no row is found.  
   *
   *  Replace the subquery by calling the get_lookup_id
   *  function for the pv_telephone_type value and
   *  assign it to a local variable.
   */
  INSERT INTO telephone
  ( contact_id
  , address_id
  , telephone_type
  , country_code
  , area_code
  , telephone_number
  , created_by
  , last_updated_by )
  VALUES
  ( lv_contact_id
  , lv_address_id
  , lv_telephone_type
  , pv_country_code
  , pv_area_code
  , pv_telephone_number
  , pv_system_user_id
  , pv_system_user_id );

EXCEPTION
  WHEN OTHERS THEN
    err_num := SQLSTATE;
    err_msg := SUBSTR(SQLERRM,1,100);
    RAISE NOTICE 'Trapped Error: %', err_msg;
END
$$ LANGUAGE plpgsql;

-- Transaction Management Example.
CREATE OR REPLACE PROCEDURE contact_insert
( IN pv_member_type         VARCHAR(30)
, IN pv_account_number      VARCHAR(10)
, IN pv_credit_card_number  VARCHAR(19)
, IN pv_credit_card_type    VARCHAR(30)
, IN pv_first_name          VARCHAR(20)
, IN pv_middle_name         VARCHAR(20)
, IN pv_last_name           VARCHAR(20)
, IN pv_contact_type        VARCHAR(30)
, IN pv_address_type        VARCHAR(30)
, IN pv_city                VARCHAR(30)
, IN pv_state_province      VARCHAR(30)
, IN pv_postal_code         VARCHAR(20)
, IN pv_street_address      VARCHAR(30)
, IN pv_telephone_type      VARCHAR(30)
, IN pv_country_code        VARCHAR(3)
, IN pv_area_code           VARCHAR(6)
, IN pv_telephone_number    VARCHAR(10)
, IN pv_user_name           VARCHAR(20)) AS
$$
DECLARE
  /* Declare a who-audit variables. */
  lv_system_user_id    INTEGER;

  /* Declare type variables. */
  lv_member_type       INTEGER;
  lv_credit_card_type  INTEGER;
  lv_contact_type      INTEGER;
  lv_address_type      INTEGER;
  lv_telephone_type    INTEGER;
  
  /* Local surrogate key variables. */
  lv_member_id          INTEGER;
  lv_contact_id         INTEGER;
  lv_address_id         INTEGER;
  lv_street_address_id  INTEGER;
  
  /* Declare local variable. */
  lv_middle_name  VARCHAR(20);

  /* Declare error handling variables. */
  err_num  TEXT;
  err_msg  INTEGER;
BEGIN

  /* Assing a null value to an empty string. */ 
  IF pv_middle_name IS NULL THEN
    lv_middle_name = '';
  END IF;

  /*
   *  Call the get_system_user_id function to assign surrogate 
   *  key value to local variable.
   */
   lv_system_user_id := get_system_user_id(pv_user_name);
  
  /*
   *  Replace the character type values with their appropriate
   *  common_lookup_id values by calling the get_lookup_id
   *  function.
   */
  lv_member_type := get_lookup_id('MEMBER', 'MEMBER_TYPE', pv_member_type);
  lv_credit_card_type := get_lookup_id('MEMBER', 'CREDIT_CARD_TYPE', pv_credit_card_type);
  lv_contact_type := get_lookup_id('CONTACT', 'CONTACT_TYPE', pv_contact_type);
  lv_address_type := get_lookup_id('ADDRESS', 'ADDRESS_TYPE', pv_address_type);
  lv_telephone_type := get_lookup_id('TELEPHONE', 'TELEPHONE_TYPE', pv_telephone_type);

  /*
   *  Check for existing member row. Assign value when one exists,
   *  and assign zero when no member row is found.
   */
  lv_member_id := get_member_id(pv_account_number);

  /*
   *  Insert into the member table when no row is found.
   *
   *  Replace the two subqueries by calling the get_lookup_id
   *  function for either the pv_member_type or credit_card_type
   *  value and assign it to a local variable.
   */
  INSERT INTO member
  ( member_type
  , account_number
  , credit_card_number
  , credit_card_type
  , created_by
  , last_updated_by )
  VALUES
  ((SELECT   common_lookup_id
    FROM     common_lookup
    WHERE    common_lookup_table = 'MEMBER'
    AND      common_lookup_column = 'MEMBER_TYPE'
    AND      common_lookup_type = pv_member_type)
  , pv_account_number
  , pv_credit_card_number
  ,(SELECT   common_lookup_id
    FROM     common_lookup
    WHERE    common_lookup_table = 'MEMBER'
    AND      common_lookup_column = 'CREDIT_CARD_TYPE'
    AND      common_lookup_type = pv_credit_card_type)
  , lv_system_user_id
  , lv_system_user_id )
  RETURNING member_id INTO lv_member_id;

  /*
   *  Insert into the member table when no row is found.
   *
   *  Replace the subquery by calling the get_lookup_id
   *  function for the pv_contact_type value and
   *  assign it to a local variable.
   */
  INSERT INTO contact
  ( member_id
  , contact_type
  , first_name
  , middle_name
  , last_name
  , created_by
  , last_updated_by )
  VALUES
  ( lv_member_id
  ,(SELECT   common_lookup_id
    FROM     common_lookup
    WHERE    common_lookup_table = 'CONTACT'
    AND      common_lookup_column = 'CONTACT_TYPE'
    AND      common_lookup_type = pv_contact_type)
  , pv_first_name
  , pv_middle_name
  , pv_last_name
  , lv_system_user_id
  , lv_system_user_id )
  RETURNING contact_id INTO lv_contact_id;

  /*
   *  Insert into the member table when no row is found.
   *
   *  Replace the subquery by calling the get_lookup_id
   *  function for the pv_address_type value and
   *  assign it to a local variable.
   */
  INSERT INTO address
  ( contact_id
  , address_type
  , city
  , state_province
  , postal_code
  , created_by
  , last_updated_by )
  VALUES
  ( lv_contact_id
  ,(SELECT   common_lookup_id
    FROM     common_lookup
    WHERE    common_lookup_table = 'ADDRESS'
    AND      common_lookup_column = 'ADDRESS_TYPE'
    AND      common_lookup_type = pv_address_type)
  , pv_city
  , pv_state_province
  , pv_postal_code
  , lv_system_user_id
  , lv_system_user_id )
  RETURNING address_id INTO lv_address_id;

  /*
   *  Insert into the member table when no row is found.
   */
  INSERT INTO street_address
  ( address_id
  , street_address
  , created_by
  , last_updated_by )
  VALUES
  ( lv_address_id
  , pv_street_address
  , lv_system_user_id
  , lv_system_user_id )
  RETURNING street_address_id INTO lv_street_address_id;

  /*
   *  Insert into the member table when no row is found.  
   *
   *  Replace the subquery by calling the get_lookup_id
   *  function for the pv_telephone_type value and
   *  assign it to a local variable.
   */
  INSERT INTO telephone
  ( contact_id
  , address_id
  , telephone_type
  , country_code
  , area_code
  , telephone_number
  , created_by
  , last_updated_by )
  VALUES
  ( lv_contact_id
  , lv_address_id
  ,(SELECT   common_lookup_id
    FROM     common_lookup
    WHERE    common_lookup_table = 'TELEPHONE'
    AND      common_lookup_column = 'TELEPHONE_TYPE'
    AND      common_lookup_type = pv_telephone_type)
  , pv_country_code
  , pv_area_code
  , pv_telephone_number
  , lv_system_user_id
  , lv_system_user_id );

EXCEPTION
  WHEN OTHERS THEN
    err_num := SQLSTATE;
    err_msg := SUBSTR(SQLERRM,1,100);
    RAISE NOTICE 'Trapped Error: %', err_msg;
END
$$ LANGUAGE plpgsql;

UPDATE system_user
SET    system_user_name = system_user_name || ' ' || system_user_id
WHERE  system_user_name = 'DBA';

/* Deleting Lensherr, McCoy, and Xavier data sets. */
SELECT 'Deleting prior data sets.' AS "Statement";
DO
$$
BEGIN
  /* Cleanup telephone table. */
  DELETE
  FROM   telephone t
  WHERE  t.contact_id IN
   (SELECT contact_id
    FROM   contact
    WHERE  last_name IN ('Lensherr','McCoy','Xavier'));
	
  /* Cleanup street_address table. */
  DELETE 
  FROM   street_address sa
  WHERE  sa.address_id IN
          (SELECT a.address_id
		   FROM   address a INNER JOIN contact c
		   ON     a.contact_id = c.contact_id
		   WHERE  c.last_name IN ('Lensherr','McCoy','Xavier'));
		   
  /* Cleanup address table. */
  DELETE
  FROM   address a
  WHERE  a.contact_id IN
   (SELECT contact_id
    FROM   contact
    WHERE  last_name IN ('Lensherr','McCoy','Xavier'));
	
  /* Cleanup contact table. */
  DELETE
  FROM    contact c
  WHERE   c.last_name IN ('Lensherr','McCoy','Xavier');

  /* Cleanup member table. */
  DELETE
  FROM   member m
  WHERE  m.account_number = 'US00010';
END;
$$;

/*DO-blocks that uses a pv_system_user_id value as the last parameter.*/
DO
$$
BEGIN
  /* Call procedure. */
  CALL contact_insert(
         'INDIVIDUAL'
        ,'US00010'
        ,'7777-6666-5555-4444'
        ,'DISCOVER_CARD'
        ,'Erik'
        ,''
        ,'Lensherr'
        ,'CUSTOMER'
        ,'HOME'
        ,'Bayville'
        ,'New York'
        ,'10032'
        ,'1407 Graymalkin Lane'
        ,'HOME'
        ,'001'
        ,'207'
        ,'111-1234'
        , 1002 );
END;
$$;

/*DO-blocks that uses a pv_user_name value as the last parameter.*/
DO
$$
DECLARE
  /* Declare the variables. */
  pv_member_type        VARCHAR(30) := 'INDIVIDUAL';
  pv_account_number     VARCHAR(10) := 'US00010';
  pv_credit_card_number VARCHAR(19) := '7777-6666-5555-4444';
  pv_credit_card_type   VARCHAR(30) := 'DISCOVER_CARD';
  pv_first_name         VARCHAR(20) := 'Charles';
  pv_middle_name        VARCHAR(20) := 'Francis';
  pv_last_name          VARCHAR(20) := 'Xavier';
  pv_contact_type       VARCHAR(30) := 'CUSTOMER';
  pv_address_type       VARCHAR(30) := 'HOME';
  pv_city               VARCHAR(30) := 'Bayville';
  pv_state_province     VARCHAR(30) := 'New York';
  pv_postal_code        VARCHAR(30) := '10032';
  pv_street_address     VARCHAR(30) := '1407 Graymalkin Lane';
  pv_telephone_type     VARCHAR(30) := 'HOME';
  pv_country_code       VARCHAR(3) := '001';
  pv_area_code          VARCHAR(6) := '207';
  pv_telephone_number   VARCHAR(10) := '111-1234';
  pv_user_name          VARCHAR(20) := 'DBA3';   
BEGIN  
  /* Call procedure. */
  CALL contact_insert(
          pv_member_type
        , pv_account_number
        , pv_credit_card_number
        , pv_credit_card_type
        , pv_first_name
        , pv_middle_name
        , pv_last_name
        , pv_contact_type
        , pv_address_type
        , pv_city
        , pv_state_province
        , pv_postal_code
        , pv_street_address
        , pv_telephone_type
        , pv_country_code
        , pv_area_code
        , pv_telephone_number
        , pv_user_name );
END;
$$;

DO
$$
DECLARE
  /* Declare the variables. */
  pv_member_type        VARCHAR(30) := 'INDIVIDUAL';
  pv_account_number     VARCHAR(10) := 'US00010';
  pv_credit_card_number VARCHAR(19) := '7777-6666-5555-4444';
  pv_credit_card_type   VARCHAR(30) := 'DISCOVER_CARD';
  pv_first_name         VARCHAR(20) := 'Henry';
  pv_middle_name        VARCHAR(20) := 'Philip';
  pv_last_name          VARCHAR(20) := 'McCoy';
  pv_contact_type       VARCHAR(30) := 'CUSTOMER';
  pv_address_type       VARCHAR(30) := 'HOME';
  pv_city               VARCHAR(30) := 'Bayville';
  pv_state_province     VARCHAR(30) := 'New York';
  pv_postal_code        VARCHAR(30) := '10032';
  pv_street_address     VARCHAR(30) := '1407 Graymalkin Lane';
  pv_telephone_type     VARCHAR(30) := 'HOME';
  pv_country_code       VARCHAR(3) := '001';
  pv_area_code          VARCHAR(6) := '207';
  pv_telephone_number   VARCHAR(10) := '111-1234';
  pv_user_name          VARCHAR(20) := 'DBA3';   
BEGIN
  /* Call procedure. */
  CALL contact_insert(
          pv_member_type
        , pv_account_number
        , pv_credit_card_number
        , pv_credit_card_type
        , pv_first_name
        , pv_middle_name
        , pv_last_name
        , pv_contact_type
        , pv_address_type
        , pv_city
        , pv_state_province
        , pv_postal_code
        , pv_street_address
        , pv_telephone_type
        , pv_country_code
        , pv_area_code
        , pv_telephone_number
        , pv_user_name );
END;
$$;

/*Test case to verify the results */
SELECT   m.account_number AS acct_no
,        CONCAT(c.last_name, ', ', c.first_name, ' ', c.middle_name) AS full_name
,        CONCAT(sa.street_address, ', ', a.city, ', ', a.state_province, ' ', a.postal_code) AS address
,       'Y' AS telephone
FROM     member m INNER JOIN contact c
ON       m.member_id = c.member_id INNER JOIN address a
ON       c.contact_id = a.contact_id INNER JOIN street_address sa
ON       a.address_id = sa.address_id INNER JOIN telephone t
ON       c.contact_id = t.contact_id
AND      a.address_id = t.address_id
WHERE    c.last_name IN ('Lensherr','Xavier','McCoy');