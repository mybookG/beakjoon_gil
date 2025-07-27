import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc =  new Scanner(System.in);
        int c = sc.nextInt();
        int result[]=new int[c];
        for (int i=0; i<c; i++) {
            result[i]=sc.nextInt()+sc.nextInt();
        }
        for (int i : result) {
            System.out.println(i);
        }
    }
}