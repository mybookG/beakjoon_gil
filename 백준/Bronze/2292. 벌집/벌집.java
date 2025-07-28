import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int output=1,check=1 ,input = sc.nextInt();
        while (input > check) {
            check+=output*6;
            output++;
        }
        System.out.println(output);
    }
}