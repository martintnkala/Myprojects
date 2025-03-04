package com.marvian.collections.hashMap;

import java.util.HashMap;
import java.util.Map;

public class Student {
    public static void main(String[] args) {
        Map<String, String> map = new HashMap<>();

        map.put("John", "Doe");
        map.put("Jane", "Doe");
        map.put("Jack", "Doe");
        map.put("Jill", "Doe");

        for (Map.Entry <String, String> entry : map.entrySet()) {
            System.out.println(entry.getKey() + " " + entry.getValue());
        }

        if (map.containsKey("John")) {
            System.out.println(map.get("John"));
        }
    }
}
