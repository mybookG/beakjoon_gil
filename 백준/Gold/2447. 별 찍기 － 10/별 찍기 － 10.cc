#include <stdio.h>
#include <stdlib.h>

void change_node(int top, int bot, int size, char** arr) {
    for (int i = top; i < top + size; i++) {
        for (int j = bot; j < bot + size; j++) {
            arr[i][j] = ' ';
        }
    }
}

void divide_node(int top, int bot, int size, char** arr) {
    if (size == 1) return;
    int newSize = size / 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) {
                change_node(top + newSize, bot + newSize, newSize, arr);
            }
            else {
                divide_node(top + i * newSize, bot + j * newSize, newSize, arr);
            }
        }
    }
}

int main() {
    int number;
    scanf("%d", &number);

    char** arr = (char**)malloc(sizeof(char*) * number);
    for (int i = 0; i < number; i++) {
        arr[i] = (char*)malloc(sizeof(char) * number);
        for (int j = 0; j < number; j++) {
            arr[i][j] = '*';
        }
    }

    divide_node(0, 0, number, arr);

    for (int i = 0; i < number; i++) {
        for (int j = 0; j < number; j++) {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < number; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
