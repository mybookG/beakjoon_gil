import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int month = sc.nextInt();
        int day = sc.nextInt();
        String[] days = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
        int monthDay[] = {0,3,3,6,1,4,6,2,5,0,3,5};
        int result = ((day-1) +monthDay[month-1])%7;
        System.out.println(days[result]);
    }
}