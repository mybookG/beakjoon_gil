import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int a,b=1;
        Scanner sc = new Scanner(System.in);
        a = sc.nextInt();
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                System.out.print("*");
            }
            System.out.println();
            b++;
        }
    }
}