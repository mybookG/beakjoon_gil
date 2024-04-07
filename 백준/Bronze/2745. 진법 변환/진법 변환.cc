#include <stdio.h>
#include <string.h>
#include <math.h>

int print(char arr[], int len, int number) {
    int total = 0;
    for (int i = 0; i < len; i++) {
        if (arr[i] >= 'A' && arr[i] <= 'Z') {
            total += (arr[i] - 'A' + 10) * pow(number, len - i - 1);
        } else if (arr[i] >= '0' && arr[i] <= '9') {
            total += (arr[i] - '0') * pow(number, len - i - 1);
        }
    }
    return total;
}

int main() {
    char arr[37] = {0};
    int number;
    scanf("%s %d", arr, &number);
    int len = strlen(arr);
    printf("%d\n", print(arr, len, number));
    return 0;
}
