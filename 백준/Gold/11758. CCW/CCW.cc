#include <stdio.h>

// 방향을 결정하는 함수
int direction(int x1, int y1, int x2, int y2, int x3, int y3) {
    // 벡터의 외적을 사용하여 방향을 판단
    int cross_product = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
    
    if (cross_product > 0) {
        return 1;  // 반시계 방향
    } else if (cross_product < 0) {
        return -1; // 시계 방향
    } else {
        return 0;  // 일직선
    }
}

int main() {
    int x1, y1, x2, y2, x3, y3;
    
    // 좌표 입력 받기
    scanf("%d %d", &x1, &y1);
    scanf("%d %d", &x2, &y2);
    scanf("%d %d", &x3, &y3);
    
    // 방향을 계산하여 출력
    int result = direction(x1, y1, x2, y2, x3, y3);
    printf("%d\n", result);
    
    return 0;
}