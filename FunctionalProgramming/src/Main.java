import java.util.*;

public class Main {
    public static void main(String[] args) {
        // NOTE: The HashSet doesn't implement ordering of elements. If you want to achieve this use a LinkedHashSet.
        System.out.println("Using HashSet:");
        Set<String> countries = new HashSet<>(List.of("Zimbabwe", "USA", "Australia", "Zambia", "Zimbabwe"));

        countries
                .forEach(System.out::println);

        System.out.println("\n\nUsing LinkedHashSet: ");
        Set<String> countries1 = new LinkedHashSet<>(List.of("Zimbabwe", "USA", "Australia", "Zambia", "Zimbabwe"));

        countries1
                .forEach(System.out::println);


    }
}