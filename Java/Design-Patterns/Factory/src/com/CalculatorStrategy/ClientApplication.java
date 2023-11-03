package com.CalculatorStrategy;

public class ClientApplication
{
    public static void main(String[] args)
    {
        Context context = new Context(new OperationAdd());
        System.out.println(context.execStrategy(10, 11));


    }
}
