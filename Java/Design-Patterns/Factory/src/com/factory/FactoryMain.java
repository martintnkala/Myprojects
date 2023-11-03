package com.factory;

import com.factory.OS;
import com.factory.OSFactory;

public class FactoryMain
{
    public static void main(String[] args)
    {
        OSFactory osf = new OSFactory();
        OS obj = osf.getInstance("Closed");
        obj.spec();


    }
}
