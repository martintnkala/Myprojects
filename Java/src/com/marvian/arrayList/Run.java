package com.marvian.arrayList;

import java.util.ArrayList;
import java.util.List;

public class Run {

    public static void main(String[] args) {
        List<Member> members = new ArrayList<Member>();

        members.add(new Member("123455", "Martin", "Nkala", "martinnkala@example", "8012348909"));

        members.forEach(System.out::println);
    }
}
