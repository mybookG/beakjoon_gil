#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000001
int checkList[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int M, N;

typedef struct {
    int xData[SIZE];
    int yData[SIZE];
    int front, rear;
} QueueType;

void init(QueueType* Q) {
    Q->front = Q->rear = 0;
}

int isEmpty(QueueType* Q) {
    return Q->front == Q->rear;
}

int isFull(QueueType* Q) {
    return Q->rear == SIZE - 1;
}

void enqueue(QueueType* Q, int x, int y) {
    if (isFull(Q)) exit(0);
    else {
        Q->xData[Q->rear] = x;
        Q->yData[Q->rear] = y;
        Q->rear++;
    }
}

void dequeue(QueueType* Q, int* x, int* y) {
    if (isEmpty(Q)) {
        return;
    }
    *x = Q->xData[Q->front];
    *y = Q->yData[Q->front];
    Q->front++;
}

int checkRange(int x, int y) {
    if (x < 0 || x >= N) return 0;
    if (y < 0 || y >= M) return 0;
    return 1;
}

int main() {
    scanf("%d%d", &M, &N);

    QueueType* QQ = (QueueType*)malloc(sizeof(QueueType));
    init(QQ);  // 큐 초기화

    int** chart = (int**)malloc(sizeof(int*) * N);
    for (int i = 0; i < N; i++) {
        chart[i] = (int*)malloc(sizeof(int) * M);
        for (int j = 0; j < M; j++) {
            scanf("%d", &chart[i][j]);
            if (chart[i][j] == 1) {
                enqueue(QQ, i, j);  // 익은 토마토 좌표 큐에 추가
            }
        }
    }

    int maxDays = 0;

    while (!isEmpty(QQ)) {  // 빈 큐가 아닐 때까지 반복
        int x, y;
        dequeue(QQ, &x, &y);

        int currentDay = chart[x][y];

        for (int i = 0; i < 4; i++) {
            int newX = x + checkList[i][0];
            int newY = y + checkList[i][1];

            if (checkRange(newX, newY) && chart[newX][newY] == 0) {
                chart[newX][newY] = currentDay + 1;
                maxDays = chart[newX][newY];
                enqueue(QQ, newX, newY);
            }
        }
    }

    int checkResult = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (chart[i][j] == 0) {
                checkResult = -1;  // 익지 않은 토마토가 있는 경우
                break;
            }
        }
        if (checkResult == -1) break;
    }

    if (checkResult == -1) {
        printf("-1\n");
    }
    else if (maxDays == 0) {
        printf("0\n");  // 처음부터 모든 토마토가 익은 경우
    }
    else {
        printf("%d\n", maxDays - 1);  // 일수를 출력 (1일차부터 시작했으므로 -1)
    }

    for (int i = 0; i < N; i++) {
        free(chart[i]);
    }
    free(chart);
    free(QQ);

    return 0;
}
