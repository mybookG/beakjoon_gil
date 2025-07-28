import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int up = sc.nextInt();
        int down = sc.nextInt();
        int peak = sc.nextInt();
        int result =1;
        peak-=up;
        result+=(int)Math.ceil((double) peak /(up-down));
        System.out.println(result);
    }
}