package com.strategy;

public class Product
{
    private final String name;
    private final String rating;
    private final String price;


    public Product(String name, String rating, String price)
    {
        this.name = name;
        this.rating = rating;
        this.price = price;
    }


    public String getName() {return name;}

    public String getRating() {return rating;}

    public String getPrice() {return price;}
}
