#include <stdio.h>
#include <stdlib.h>

void change_node(int top, int bot, int size, char** arr) {
    for (int i = top; i < top + size; i++) 
        for (int j = bot; j < bot + 2 * size-1; j++) 
            if ((j - bot >= i - top && (j - bot) < (size * 2 - 1 - i + top))) 
                arr[i][j] = ' ';
}

void divide_node(int top, int bot, int size, char** arr) {
    if (size <= 3) return;
    int newSize = size / 2;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) {
                change_node(top + newSize, bot + newSize, newSize, arr);
            }
            else if(i==1){
                divide_node(top + newSize, bot + j * newSize, newSize, arr);
            }
            else if (j==1){
                divide_node(top, bot + newSize, newSize, arr);
            }
        }
    }
}

int main() {
    int number;
    scanf("%d", &number);

    char** arr = (char**)malloc(sizeof(char*) * number);
    for (int i = 0; i < number; i++) {
        arr[i] = (char*)malloc(sizeof(char) * (number * 2 - 1));
        for (int j = 0; j < number*2-1; j++) {
            if (number - (i + 1) < (j + 1) && (j + 1) < number + (i + 1)) {
                if (2 * (i + 1) % 3 == 1&& 2 * (j + 1) % 3 == 0) arr[i][j] = ' ';
                else arr[i][j] = '*';
            }
            else arr[i][j] = ' ';
        }
    }
    divide_node(0, 0, number,arr);

    for (int i = 0; i < number; i++) {
        for (int j = 0; j < number * 2 -1; j++) {
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
