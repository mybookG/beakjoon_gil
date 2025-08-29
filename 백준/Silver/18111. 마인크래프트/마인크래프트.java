import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        int B = sc.nextInt();

        int[] block = new int[257];
        int minH = 256, maxH = 0;

        for (int i = 0; i < N * M; i++) {
            int h = sc.nextInt();
            block[h]++;
            minH = Math.min(minH, h);
            maxH = Math.max(maxH, h);
        }

        // prefix sum 준비
        long[] cntSum = new long[257];  // 블록 개수 누적합
        long[] heightSum = new long[257]; // 높이 * 블록 개수 누적합
        for (int i = 0; i <= 256; i++) {
            if (i > 0) {
                cntSum[i] = cntSum[i-1] + block[i];
                heightSum[i] = heightSum[i-1] + (long) block[i] * i;
            } else {
                cntSum[i] = block[i];
                heightSum[i] = (long) block[i] * i;
            }
        }

        long resultTime = Long.MAX_VALUE;
        int resultHeight = 0;

        for (int target = minH; target <= maxH; target++) {
            // target보다 낮은 곳 블록 설치
            long lowerCnt = target > 0 ? cntSum[target-1] : 0;
            long lowerSum = target > 0 ? heightSum[target-1] : 0;
            long build = (long) target * lowerCnt - lowerSum;

            // target보다 높은 곳 블록 제거
            long higherCnt = cntSum[256] - cntSum[target];
            long higherSum = heightSum[256] - heightSum[target];
            long remove = higherSum - (long) target * higherCnt;

            // 인벤토리 확인
            if (build > remove + B) continue;

            long time = remove * 2 + build;
            if (time < resultTime || (time == resultTime && target > resultHeight)) {
                resultTime = time;
                resultHeight = target;
            }
        }

        System.out.println(resultTime + " " + resultHeight);
    }
}
