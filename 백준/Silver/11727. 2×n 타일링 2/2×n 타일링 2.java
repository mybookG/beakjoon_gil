import java.util.Scanner;

public class Main {
    static final int MOD = 10007;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int input = sc.nextInt();
        long result = 0;
        for (int i = 0; i <= input; i+=2) {
            int a = input - i + i / 2;  // 조합의 n
            int b = i / 2;              // 조합의 r

            long numerator = factorial(a); // n!
            long denominator = (factorial(a - b) * factorial(b)) % MOD; // r!(n-r)!
            long inverse = modInverse(denominator); // 모듈러 역원

            long check = (numerator * inverse*pow(2,b)) % MOD;
            result = (result + check) % MOD;
        }
        System.out.println(result%MOD);
    }

    public static long factorial(int n) {
        long result = 1;
        for (int i = 2; i <= n; i++) {
            result = (result*i)%MOD;
        }
        //System.out.println(result);
        return result;
    }
    public static long modInverse(long a) {
        return pow(a, MOD - 2);
    }

    public static long pow(long base, int exp) {
        long result = 1;
        base %= MOD;
        while (exp > 0) {
            if ((exp & 1) == 1) result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return result;
    }
}