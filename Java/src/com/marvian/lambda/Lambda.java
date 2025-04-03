import com.marvian.lambda.Printable;

public static void main(String[] args) {

        Printable printable;

        printable = () -> System.out.println("meow");
        printable.print();

    }

