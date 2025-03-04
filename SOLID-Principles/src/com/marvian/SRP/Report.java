package com.marvian.SRP;

public class Report {

     void generateReport(String format) {
        if (format.equals("csv")) {
            System.out.println("Generating CSV report");
        }
        if (format.equals("xml")) {
            System.out.println("Generating XML report");
        }
        if (format.equals("json")) {
            System.out.println("Generating JSON report");
        }
    }

     void saveToFile(String fileName, String format) {
        if (format.equals("csv")) {
            fileName = fileName + ".csv";
            System.out.println("Saving: " + fileName);
        }
        if (format.equals("xml")) {
            fileName = fileName + ".xml";
            System.out.println("Saving: " + fileName);
        }
        if (format.equals("pdf")) {
            fileName = fileName + ".pdf";
            System.out.println("Saving: " + fileName);
        }
    }
}
