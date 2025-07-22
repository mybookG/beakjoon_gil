import java.util.Scanner;

public class Main{
    public static int getMath(int a, int b){
        int totalA=1, totalB=1;
        for (int i = 0; i <= a; i++) {
            totalA *= i+1;
            totalB *= b+i;
        }
        return totalB/totalA;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int TestCase = sc.nextInt(), k, n;
        int array[] = new int[TestCase];
        for (int i = 0; i < TestCase; i++) {
            k = sc.nextInt();
            n = sc.nextInt();
            int test[][] = new int[k][n];
            for (int j = 0; j < k; j++) {
                for (int l = 0; l < n; l++) {
                    if(l==0)        test[j][l]=1;
                    else if(j==0)   test[j][l]=test[j][l-1]+l+1;
                    else            test[j][l] = test[j][l - 1] + test[j - 1][l];
                }
            }
            array[i]=test[k-1][n-1];
        }

        for (int i = 0; i < TestCase; i++) {
            System.out.println(array[i]);
        }
    }
}