package Nkala;

import java.sql.*;
import java.util.Scanner;

public class Database {
    public static final String DB_NAME  = "mydatabase.db";
    public static final String CONNECTION_STRING = "jdbc:sqlite:" + DB_NAME;
    /**
     * Here I am creating constants for  my Tables, database name, my connection, and columns.
     * This will allow me to make changes in my code on one spot instead of replicating same columns names multiple times.
     */
//    All my tables
    public static final String TABLE_PEOPLE = "people";
    public static final String  TABLE_ADDRESS = "address";
    public static final String  TABLE_CAR = "car";

//    Column names for the People Table
    public static final String COLUMN_ID = "id";
    public static final String COLUMN_NAME = "fname";
    public static final String COLUMN_MIDDLE_NAME = "mname";
    public static final String COLUMN_LAST_NAME = "lname";

//    Column name for the Address Table
    public static final String COLUMN_ADDRESS_ID = "addr_id";
    public static final String COLUMN_STREET_ADDRESS = "streetAddress";
    public static final String COLUMN_APARTMENT_NUMBER = "apartmentNumber";
    public static final String  COLUMN_CITY = "city";
    public static final String COLUMN_STATE = "state";
    public static final String COLUMN_ZIP_CODE = "zipCode";

//    Column names for the car Table

    public static final String COLUMN_VIN_NUMBER = "vinNumber";
    public static final String  COLUMN_MODEL = "model";
    public static final String COLUMN_COLOR = "color";

    public static void main(String[] args) {
        /**
         * I am using "Try and Catch " first for error handling and secondly to establish a connection with the SQLite database
         * using the jdbc driver. To connect a database using SQLite always remember to start with "jdbc:sqlite" and then the absolute path and then at end that path you need to
         * type in the database name with the .db extension. Otherwise, SQLite will create one for you by default.
         */
        try {
//            /Users/marvian/Projects/SQL/SQL-JAVA/
            Connection conn = DriverManager.getConnection(CONNECTION_STRING);
            Statement statement = conn.createStatement();

//            Recreating all tables if they have been created already
            statement.execute("DROP TABLE IF EXISTS " + TABLE_PEOPLE );
            statement.execute("DROP TABLE IF EXISTS " + TABLE_ADDRESS );
            statement.execute("DROP TABLE IF EXISTS " + TABLE_CAR);

            /**
             * I used the IF NOT EXISTS keywords so that the SQlite engine checks to see if the table exists or not.
             * If it doesn't exist it will not create it.
             */
            statement.execute("CREATE TABLE IF NOT EXISTS " + TABLE_PEOPLE +
                            " (" + COLUMN_ID + " int primary key not null, " +
                            COLUMN_NAME + " varchar(20) not null, " +
                            COLUMN_MIDDLE_NAME + " varchar(20), " +
                            COLUMN_LAST_NAME + " varchar(20) not null " + ")");

            statement.execute("CREATE TABLE IF NOT EXISTS " + TABLE_ADDRESS +
                    " (" + COLUMN_ADDRESS_ID + " int primary key not null, " +
                    COLUMN_STREET_ADDRESS + " varchar(20) not null, " +
                    COLUMN_APARTMENT_NUMBER + " int not null, " +
                    COLUMN_CITY + " varchar(30) not null, " +
                    COLUMN_STATE + " varchar(30) not null, " +
                    COLUMN_ZIP_CODE + " varchar(10) not null " + ")");

            statement.execute("CREATE TABLE IF NOT EXISTS " + TABLE_CAR +
                    " (" + COLUMN_VIN_NUMBER + " int primary key not null, " +
                    COLUMN_MODEL + " varchar(20) not null, " +
                    COLUMN_COLOR + " varchar(20) not null " + ")");

            /**
             * I did some Inserts into all the tables I created. If you are using all the columns in your table you
             * don't have to specify the columns but rather inside the Value's keyword just make sure you put in
             * data for every column name otherwise you will have some errors.
             */
             //            Inserts Into the People Table

            insertPeople(statement, 01,"Martin", "Takudzwa", "Nkala");
            insertPeople(statement, 02,"Seth", "Mufaro", "Gwatirera");
            insertPeople(statement, 03,"Nomthandazo", "Audrey", "Nkala");
            insertPeople(statement, 04,"vivian", "Abby", "Gwatirera");
            insertAddress(statement,001, "234 N. 5th W", 100011, "Rexburg", "Idaho", 83440);
            insertAddress(statement,002, "256 W. 4th S", 100021, "Rexburg", "Idaho", 83440);
            insertAddress(statement,003, "234 N. 5th W", 100012, "Rexburg", "Idaho", 83440);
            insertAddress(statement,004, "234 N. 5th W", 100013, "Rexburg", "Idaho", 83440);
            insertCar(statement,"1GH0000134111EG00", "BWM-320i", "White");
            insertCar(statement,"1GH0000234111EG11", "Ford Taurus", "Red");
            insertCar(statement,"1GH0000234111EG33", "Nissan Sentra", "Black");



            ResultSet results = statement.executeQuery("SELECT * FROM " + TABLE_PEOPLE);
            while(results.next()){
                System.out.println(results.getString("fname")+ ", " +
                                results.getString("mname")+ ", " +
                                results.getString("lname"));
            }
            results.close();


            statement.close();
            conn.close();


        } catch (SQLException e) {
            System.out.println("Something went wrong" + e.getMessage());
            e.printStackTrace();
        }

    }


    private static void insertPeople(Statement statement, int id, String fname, String mname, String lname) throws  SQLException{
        statement.execute("INSERT INTO " + TABLE_PEOPLE +
                "(" + COLUMN_ID + ", " +
                COLUMN_NAME + ", " +
                COLUMN_MIDDLE_NAME + ", " +
                COLUMN_LAST_NAME + ")" +
                " VALUES ("+ id + ",'" + fname + "','" + mname + "', '"+ lname +"')");
    }

    private  static  void  insertAddress(Statement statement, int addr_id, String streetAddress, int apartmentNumber, String city, String state, int zipCode) throws SQLException{
        statement.execute("INSERT INTO " + TABLE_ADDRESS +
                "(" + COLUMN_ADDRESS_ID + ", " +
                COLUMN_STREET_ADDRESS + ", " +
                COLUMN_APARTMENT_NUMBER + ", " +
                COLUMN_CITY + ", " +
                COLUMN_STATE + ", " +
                COLUMN_ZIP_CODE  + ")" +
                " VALUES ("+addr_id+", '"+streetAddress+"', "+apartmentNumber+", '" +city+ "', '" + state+ "',"+zipCode+")");
    }

    private static void insertCar(Statement statement, String vinNumber, String model, String color) throws SQLException{
        statement.execute("INSERT INTO " + TABLE_CAR +
                " (" + COLUMN_VIN_NUMBER + ", " +
                COLUMN_MODEL + ", " +
                COLUMN_COLOR + ")" +
                " VALUES ('"+vinNumber+"', '"+model+"', '" +color+ "')" );
    }
}
