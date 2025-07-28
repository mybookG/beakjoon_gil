import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int fractions[] = new int[2];
        int check = 1, input = sc.nextInt();
            while (input > check) {
                input -= check;
                check++;
            }
            if (check % 2 == 1) {
                fractions[0] = check +1 -input;
                fractions[1] = input;
            } else {
                fractions[1] = check +1 -input;
                fractions[0] = input;
            }
            System.out.println(fractions[0] + "/" + fractions[1]);

    }
}