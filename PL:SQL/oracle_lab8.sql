SET ECHO ON
SET DEFINE ON
SET SERVEROUTPUT ON SIZE UNLIMITED
SET FEEDBACK ON

 
-- Update system_user to ensure unique system_user_name values
UPDATE system_user
SET system_user_name = system_user_name || ' ' || system_user_id
WHERE system_user_name = 'DBA';

-- Clean prior test data
BEGIN
  DELETE FROM telephone WHERE contact_id > 1018;
  DELETE FROM street_address WHERE address_id > 1018;
  DELETE FROM address WHERE address_id > 1018;
  DELETE FROM contact WHERE contact_id > 1018;
  DELETE FROM member WHERE member_id > 1018;
END;
/

CREATE OR REPLACE PROCEDURE insert_contact
( pv_first_name          VARCHAR2
, pv_middle_name         VARCHAR2 := NULL
, pv_last_name           VARCHAR2
, pv_contact_type        VARCHAR2
, pv_account_number      VARCHAR2
, pv_member_type         VARCHAR2
, pv_credit_card_number  VARCHAR2
, pv_credit_card_type    VARCHAR2
, pv_street_address      VARCHAR2
, pv_city                VARCHAR2
, pv_state_province      VARCHAR2
, pv_postal_code         VARCHAR2
, pv_address_type        VARCHAR2
, pv_country_code        VARCHAR2
, pv_area_code           VARCHAR2
, pv_telephone_number    VARCHAR2
, pv_telephone_type      VARCHAR2
, pv_user_name           VARCHAR2 ) IS
 

  lv_current_date      DATE := TRUNC(SYSDATE);
 
  
  lv_created_by        NUMBER;
  lv_updated_by        NUMBER;
  lv_system_user_id    NUMBER;
 

  lv_member_type       NUMBER;
  lv_credit_card_type  NUMBER;
  lv_contact_type      NUMBER;
  lv_address_type      NUMBER;
  lv_telephone_type    NUMBER;

  lv_member_id          NUMBER;
  lv_contact_id         NUMBER;
  lv_address_id         NUMBER;
  lv_street_address_id  NUMBER;
  lv_telephone_id       NUMBER;
 
  FUNCTION get_lookup_type 
  ( pv_table_name    VARCHAR2
  , pv_column_name   VARCHAR2
  , pv_type_name     VARCHAR2 ) RETURN NUMBER IS
 
    
    lv_retval  NUMBER := 0;
 
   
    CURSOR get_lookup_value
    ( cv_table_name    VARCHAR2
    , cv_column_name   VARCHAR2
    , cv_type_name     VARCHAR2 ) IS
      SELECT common_lookup_id
      FROM   common_lookup
      WHERE  common_lookup_table = cv_table_name
      AND    common_lookup_column = cv_column_name
      AND    common_lookup_type = cv_type_name;
 
  BEGIN
 
  
    FOR i IN get_lookup_value(pv_table_name, pv_column_name, pv_type_name) LOOP
      lv_retval := i.common_lookup_id;
    END LOOP;
 
   
    RETURN lv_retval;
  END get_lookup_type;

  FUNCTION get_member_id
  ( pv_account_number  VARCHAR2 ) RETURN NUMBER IS

    lv_retval  NUMBER := 0;  -- Default value is 0.

    CURSOR find_member_id
    ( cv_account_number  VARCHAR2 ) IS
      SELECT   m.member_id
	  FROM     member m
	  WHERE    m.account_number = cv_account_number;
  BEGIN  
    FOR i IN find_member_id(pv_account_number) LOOP
      lv_retval := i.member_id;
    END LOOP;

    RETURN lv_retval;
  END get_member_id;
BEGIN
  SAVEPOINT startingpoint;
 
  
  lv_member_type := get_lookup_type('MEMBER','MEMBER_TYPE', pv_member_type);
 
  
  lv_credit_card_type := get_lookup_type('MEMBER','CREDIT_CARD_TYPE', pv_credit_card_type);
 
  
  lv_contact_type := get_lookup_type('CONTACT','CONTACT_TYPE', pv_contact_type);
 
 
  lv_address_type := get_lookup_type('ADDRESS','ADDRESS_TYPE', pv_address_type);
 
  
  lv_telephone_type := get_lookup_type('TELEPHONE','TELEPHONE_TYPE', pv_telephone_type);
 
  
  SELECT system_user_id
  INTO   lv_system_user_id
  FROM   system_user
  WHERE  system_user_name = pv_user_name;
 
  
  lv_created_by := lv_system_user_id;
  lv_updated_by := lv_system_user_id;
 
  
  lv_member_id := get_member_id(pv_account_number);
 
  IF lv_member_id = 0 THEN

    INSERT INTO member
    ( member_id
    , member_type
    , account_number
    , credit_card_number
    , credit_card_type
    , created_by
    , creation_date
    , last_updated_by
    , last_update_date )
    VALUES
    ( member_s1.NEXTVAL
    , lv_member_type
    , pv_account_number
    , pv_credit_card_number
    , lv_credit_card_type
	, lv_created_by
    , lv_current_date
    , lv_updated_by
    , lv_current_date )
	RETURNING member_id INTO lv_member_id;
  END IF;
 
  
  INSERT INTO contact
  ( contact_id
  , member_id
  , contact_type
  , last_name
  , first_name
  , middle_name
  , created_by
  , creation_date
  , last_updated_by
  , last_update_date)
  VALUES
  ( contact_s1.NEXTVAL
  , lv_member_id
  , lv_contact_type
  , pv_last_name
  , pv_first_name
  , pv_middle_name
  , lv_created_by
  , lv_current_date
  , lv_updated_by
  , lv_current_date )
  RETURNING contact_id INTO lv_contact_id;

  INSERT INTO address
  ( address_id
  , contact_id
  , address_type
  , city
  , state_province
  , postal_code
  , created_by
  , creation_date
  , last_updated_by
  , last_update_date )
  VALUES
  ( address_s1.NEXTVAL
  , lv_contact_id
  , lv_address_type
  , pv_city
  , pv_state_province
  , pv_postal_code
  , lv_created_by
  , lv_current_date
  , lv_updated_by
  , lv_current_date )
  RETURNING address_id INTO lv_address_id;

  INSERT INTO street_address
  ( street_address_id
  , address_id
  , line_number
  , street_address
  , created_by
  , creation_date
  , last_updated_by
  , last_update_date )
  VALUES
  ( street_address_s1.NEXTVAL
  , lv_address_id
  , 1
  , pv_street_address
  , lv_created_by
  , lv_current_date
  , lv_updated_by
  , lv_current_date );
 
  
  INSERT INTO telephone
  ( telephone_id
  , contact_id
  , address_id
  , telephone_type
  , country_code
  , area_code
  , telephone_number
  , created_by
  , creation_date
  , last_updated_by
  , last_update_date )
  VALUES
  ( telephone_s1.NEXTVAL  -- TELEPHONE_ID
  , lv_contact_id         -- CONTACT_ID
  , lv_address_id         -- ADDRESS_ID
  , lv_telephone_type     -- TELEPHONE_TYPE
  , pv_country_code       -- COUNTRY_CODE
  , pv_area_code          -- AREA_CODE
  , pv_telephone_number   -- TELEPHONE_NUMBER
  , lv_created_by         -- CREATED_BY
  , lv_current_date       -- CREATION_DATE
  , lv_updated_by         -- LAST_UPDATED_BY
  , lv_current_date);     -- LAST_UPDATE_DATE

  COMMIT;
 
EXCEPTION
  WHEN OTHERS THEN
	dbms_output.put_line('['||SQLERRM||']');
    ROLLBACK TO startingpoint;
END insert_contact;
/
 
BEGIN
 
  insert_contact(
      pv_first_name         => 'Charles'
    , pv_middle_name        => 'Francis'
    , pv_last_name          => 'Xavier'
    , pv_contact_type       => 'CUSTOMER'
    , pv_account_number     => 'SLC-000008'
    , pv_member_type        => 'INDIVIDUAL'
    , pv_credit_card_number => '7777-6666-5555-4444'
    , pv_credit_card_type   => 'DISCOVER_CARD'
    , pv_street_address     => '1407 Graymalkin Lane' 
    , pv_city               => 'Bayville'
    , pv_state_province     => 'New York'
    , pv_postal_code        => '10032'
    , pv_address_type       => 'HOME'
    , pv_country_code       => '001'
    , pv_area_code          => '207'
    , pv_telephone_number   => '111-1234'
    , pv_telephone_type     => 'HOME'
    , pv_user_name          => 'DBA 2'
    );
 

  insert_contact(
      pv_first_name         => 'James'
    , pv_last_name          => 'Xavier'
    , pv_contact_type       => 'CUSTOMER'
    , pv_account_number     => 'SLC-000008'
    , pv_member_type        => 'INDIVIDUAL'
    , pv_credit_card_number => '7777-6666-5555-4444'
    , pv_credit_card_type   => 'DISCOVER_CARD'
    , pv_street_address     => '1407 Graymalkin Lane' 
    , pv_city               => 'Bayville'
    , pv_state_province     => 'New York'
    , pv_postal_code        => '10032'
    , pv_address_type       => 'HOME'
    , pv_country_code       => '001'
    , pv_area_code          => '207'
    , pv_telephone_number   => '111-1234'
    , pv_telephone_type     => 'HOME'
    , pv_user_name          => 'DBA 2'
    );
END;
/
 
COLUMN account_number  FORMAT A10  HEADING "Account|Number"
COLUMN contact_name    FORMAT A30  HEADING "Contact Name"
SELECT m.account_number
,      c.last_name ||', '||c.first_name AS contact_name
FROM   member m INNER JOIN contact c
ON     m.member_id = c.member_id
WHERE  m.account_number = 'SLC-000008';
