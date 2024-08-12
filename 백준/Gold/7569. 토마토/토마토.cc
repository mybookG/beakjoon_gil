#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000001
int checkList[6][3] = { {-1, 0, 0}, {1, 0, 0}, {0, -1, 0}, {0, 1, 0}, {0, 0, -1}, {0, 0, 1} };
int M, N, H;

typedef struct {
    int xData[SIZE];
    int yData[SIZE];
    int zData[SIZE];
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

void enqueue(QueueType* Q, int x, int y, int z) {
    if (isFull(Q)) exit(0);
    Q->xData[Q->rear] = x;
    Q->yData[Q->rear] = y;
    Q->zData[Q->rear] = z;
    Q->rear++;
}

void dequeue(QueueType* Q, int* z, int* y, int* x) {
    if (isEmpty(Q)) return;
    *x = Q->xData[Q->front];
    *y = Q->yData[Q->front];
    *z = Q->zData[Q->front];
    Q->front++;
}

int checkRange(int z, int y, int x) {
    if (x < 0 || x >= M) return 0;
    if (y < 0 || y >= N) return 0;
    if (z < 0 || z >= H) return 0;
    return 1;
}

int main() {
    scanf("%d%d%d", &M, &N, &H);

    QueueType* QQ = (QueueType*)malloc(sizeof(QueueType));
    init(QQ);

    int*** chart = (int***)malloc(sizeof(int**) * H);
    for (int i = 0; i < H; i++) {
        chart[i] = (int**)malloc(sizeof(int*) * N);
        for (int j = 0; j < N; j++) {
            chart[i][j] = (int*)malloc(sizeof(int) * M);
            for (int k = 0; k < M; k++) {
                scanf("%d", &chart[i][j][k]);
                if (chart[i][j][k] == 1) {
                    enqueue(QQ, k, j, i);
                }
            }
        }
    }

    int maxDays = 0;

    while (!isEmpty(QQ)) {
        int x, y, z;
        dequeue(QQ, &z, &y, &x);

        int currentDay = chart[z][y][x];

        for (int i = 0; i < 6; i++) {
            int newX = x + checkList[i][0];
            int newY = y + checkList[i][1];
            int newZ = z + checkList[i][2];

            if (checkRange(newZ, newY, newX) && chart[newZ][newY][newX] == 0) {
                chart[newZ][newY][newX] = currentDay + 1;
                maxDays = chart[newZ][newY][newX];
                enqueue(QQ, newX, newY, newZ);
            }
        }
    }

    int checkResult = 0;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (chart[i][j][k] == 0) {
                    checkResult = -1;
                    break;
                }
            }
            if (checkResult == -1) break;
        }
        if (checkResult == -1) break;
    }

    if (checkResult == -1) {
        printf("-1\n");
    }
    else if (maxDays == 0) {
        printf("0\n");
    }
    else {
        printf("%d\n", maxDays - 1);
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            free(chart[i][j]);
        }
        free(chart[i]);
    }
    free(chart);
    free(QQ);

    return 0;
}
