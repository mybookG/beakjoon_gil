import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int a, b,c ;
        Scanner sc = new Scanner(System.in);
        a = sc.nextInt();
        b = sc.nextInt();
        ArrayList<Integer> result = new ArrayList<>();
        for (int i = 0; i < a; i++) {
            if((c=sc.nextInt()) <b) {
                result.add(c);
            }
        }
        for(Integer i : result) {
            System.out.println(i);
        }
    }
}