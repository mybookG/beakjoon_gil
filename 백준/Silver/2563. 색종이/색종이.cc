#include <stdio.h>
#include <stdlib.h>

void check(int row, int height, int **container) {
    for (int r = row; r < row + 10 && r < 101; r++) {
        for (int h = height; h < height + 10 && h < 101; h++) {
            container[h][r] = 1;
        }
    }
}

int print(int **container) {
    int total = 0;
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            if (container[i][j] == 1) total++;
        }
    }
    return total;
}

int main() {
    int **container;
    int number, row, height;
    scanf("%d", &number);
    
    container = (int **)malloc(101 * sizeof(int *));
    for (int i = 0; i < 101; i++) {
        container[i] = (int *)malloc(101 * sizeof(int));
    }

    for (int i = 0; i < number; i++) {
        scanf("%d %d", &row, &height);
        check(row, height, container);
    }

    printf("%d", print(container));

    for (int i = 0; i < 101; i++) {
        free(container[i]);
    }
    free(container);

    return 0;
}
