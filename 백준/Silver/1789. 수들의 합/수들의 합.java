import java.util.Scanner;

import static java.lang.Math.sqrt;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long S = sc.nextLong();
        int i = (int)(-1 + (int)sqrt(1+8*S))/2;
        System.out.println(i);
    }
}