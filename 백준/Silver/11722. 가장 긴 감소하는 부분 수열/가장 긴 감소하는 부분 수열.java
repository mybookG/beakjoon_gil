import java.util.Scanner;

import static java.lang.Math.max;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int arr[] = new int[N];
        int counter[] = new int[N];
        int check = 1;
        for (int i = 0; i < N; i++) {
            arr[i] = sc.nextInt();
            counter[i]=1;
            for (int j = 0; j < i; j++) {
                if (arr[i] < arr[j]) {
                    counter[i]=max(counter[i],counter[j]+1);
                }
            }
            if(counter[i]>check){
                check=counter[i];
            }
        }
        System.out.println(check);
    }
}