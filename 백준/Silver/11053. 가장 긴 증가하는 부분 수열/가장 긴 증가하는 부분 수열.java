import java.util.Scanner;

import static java.lang.Math.max;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int A[] = new int[N];
        int dp[] = new int[N];
        int check=1;
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
            dp[i]=1;
            for(int j =0;j<i;j++){
                if(A[j]<A[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            if(check<dp[i])check=dp[i];
        }
        System.out.println(check);
    }
}