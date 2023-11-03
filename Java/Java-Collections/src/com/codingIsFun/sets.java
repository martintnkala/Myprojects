package com.codingIsFun;

public class sets
{

    public static void main(String[] args)
    {
        Database database = Database.getInstance();

    }

}

// Singleton design pattern
class Database
{
    // The constructor must be private
    Database database = new Database();
    private Database() {}
    // The method must be public
    public static Database getInstance()
    {
       return database;
    }

}



