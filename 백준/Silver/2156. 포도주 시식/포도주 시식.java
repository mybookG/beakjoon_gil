import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int win[] = new int[n];
        for (int i = 0; i < n; i++) {
            win[i] = sc.nextInt();
        }
        int dp[]=new int[n];
        dp[0]=win[0];
        if (n ==1){
            System.out.println(dp[0]);
            return;
        }
        dp[1]=win[1]+win[0];
        if (n ==2){
            System.out.println(dp[1]);
            return;
        }
        dp[2]=max(dp[1],win[2]+win[0],win[2]+win[1]);
        if (n ==3){
            System.out.println(dp[2]);
            return;
        }
        for(int i=3;i<n;i++){
            dp[i]=max(dp[i-1],dp[i-2]+win[i],dp[i-3]+win[i-1]+win[i]);
        }
        System.out.println(dp[n-1]);
    }
    public static int max(int a,int b,int c){
        a = (a>b)?a:b;
        a = (a>c)?a:c;
        return a;
    }
}