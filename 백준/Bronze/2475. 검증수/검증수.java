import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int result[] = new int[6];
        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < 5; i++) {
            result[i] = sc.nextInt();
            result[5] += (int) Math.pow(result[i],2);
        }
        System.out.println(result[5]%10);
    }
}