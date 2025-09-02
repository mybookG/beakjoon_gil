import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

import static java.lang.Math.max;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[][] arr=new int[3][N];
        int check=1;
        for(int i=0;i<N;i++){
            arr[0][i]=sc.nextInt();
            arr[1][i]=1;
            for(int j=0;j<i;j++){
                if(arr[0][j]<arr[0][i]){
                    arr[1][i]=max(arr[1][i],arr[1][j]+1);
                }
            }
        }
        for(int i=N-1;i>=0;i--){
            arr[2][i]=1;
            for(int j=N-1;j>i;j--){
                if(arr[0][j]<arr[0][i]){
                    arr[2][i]=max(arr[2][i],arr[2][j]+1);
                }
            }
            if(arr[1][i]+arr[2][i]>check){
                check=arr[1][i]+arr[2][i];
            }
        }
        System.out.println(check-1);
    }
}