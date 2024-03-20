/* Drop conditionally to avoid dependency issues. */
DROP TABLE IF EXISTS conquistador;
DROP VIEW IF EXISTS conquistador_de;
DROP FUNCTION IF EXISTS getConquistador;
DROP TYPE IF EXISTS conquistador_struct;

/* Create avenger table. */
CREATE TABLE conquistador
( conquistador_id   SERIAL
, conquistador      VARCHAR(30)
, actual_name       VARCHAR(30)
, nationality       VARCHAR(30)
, lang              VARCHAR(2));

/* Insert 9-rows of data. */
INSERT INTO conquistador
( conquistador
, actual_name
, nationality
, lang )
VALUES
 ('Juan de Fuca','Ioánnis Fokás','Greek','el')
,('Nicolás de Federmán','Nikolaus Federmann','German','de')
,('Sebastián Caboto','Sebastiano Caboto','Venetian','it')
,('Jorge de la Espira','Georg von Speyer','German','de')
,('Eusebio Francisco Kino','Eusebius Franz Kühn','Italian','it')
,('Wenceslao Linck','Wenceslaus Linck','Bohemian','cs')
,('Fernando Consag','Ferdinand Konšcak','Croatian','sr')
,('Américo Vespucio','Amerigo Vespucci','Italian','it')
,('Alejo García','Aleixo Garcia','Portuguese','pt');

/* Create a type to use as a row structure. */
CREATE TYPE conquistador_struct AS
(   conquistador      VARCHAR(30)
    , actual_name     VARCHAR(30)
    , nationality      VARCHAR(30));

/* Create a table function that returns a set of a structure. */
CREATE FUNCTION getConquistador (IN lang_in VARCHAR(2))
  RETURNS SETOF conquistador_struct AS
$$
BEGIN
  RETURN QUERY
  SELECT c.conquistador
  ,      c.actual_name
  ,      c.nationality
  FROM   conquistador c
  WHERE  c.lang = lang_in;
END;
$$ LANGUAGE plpgsql;

-- SELECT * FROM getConquistador('de');

/* Creating a conquistador VIEW */
CREATE OR REPLACE
  VIEW conquistador_de AS
  SELECT * FROM getConquistador('de'); 
  
/* Querying the VIEW */
SELECT * FROM conquistador_de;

