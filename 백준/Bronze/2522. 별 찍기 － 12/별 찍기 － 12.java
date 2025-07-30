import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int input = sc.nextInt();
        for (int i = 1; i < input*2; i++) {
            for (int j = 0; j <input ; j++) {
                if((i<input&&input-i<=j)||(i>=input&&i-input<=j)){
                    System.out.print("*");
                }else {
                    System.out.print(" ");
                }
            }
            System.out.println();
        }
    }
}