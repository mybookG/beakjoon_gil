import java.util.Scanner;

import static java.lang.Math.max;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int arr[] = new int[N];
        int check[] = new int[N];
        int result =0;
        for (int i = 0; i < N; i++) {
            arr[i] = sc.nextInt();
            check[i] = arr[i];
            for (int j = 0; j < i; j++) {
                if(arr[i] > arr[j]) {
                    check[i]=max(check[i],check[j]+arr[i]);
                }
            }
            if(check[i]>result) {
                result=check[i];
            }
        }
        System.out.println(result);
    }
}