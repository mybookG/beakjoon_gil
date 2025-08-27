import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long A = sc.nextLong();
        long B = sc.nextLong();
        long result=0;
        long counter=0;
        Queue<Long> list = new ArrayDeque<>();
        Queue<Long> check = new ArrayDeque<>();
        list.add(A);
        check.add(1L);
        while (!list.isEmpty() && result != B) {
            result = list.remove();
            counter = check.remove();
            //System.out.prlongln("re:"+result);
            long way1 = result*10+1;
            long way2 = result*2;
            if(way2<=B){
                list.add(way2);
                check.add(counter+1);
                //System.out.prlong(" 2:"+way2);
            }
            if(way1<=B){
                list.add(way1);
                check.add(counter+1);
                //System.out.prlong(" 1:"+way1);
            }
        }
        if(result!=B){
            counter = -1;
        }
        System.out.println(counter);
    }
}