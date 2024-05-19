#include <stdio.h>
#include <stdlib.h>

int main() {
	int total,min,max;
	scanf("%d", &total);
	int* arr = (int*)malloc(sizeof(int) * total);
	if (arr == NULL)return 0;
	for (int i = 0; i < total; i++) {scanf("%d", &arr[i]);}
	min = arr[0];
	max = arr[0];
	for (int i = 1; i < total; i++) {
		if (arr[i] < min) { min=arr[i]; }
	}
	for (int i = 1; i < total; i++) {
		if (arr[i] > max) { max=arr[i]; }
	}
	printf("%ld", min * max);
	free(arr);
	return 0;
}