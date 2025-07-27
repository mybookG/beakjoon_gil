import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        double a, b;
        Scanner sc = new Scanner(System.in);
        a = sc.nextInt();
        b = sc.nextInt();
        double c = a/b;
        System.out.printf("%.10f\n", c);
    }
}