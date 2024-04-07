#include <stdio.h>
#include <stdlib.h>

int main() {
	int a, b,plus;
	int* arr;
	scanf("%d %d", &a, &b);
	plus = a * b;
	do { arr = (int*)malloc(plus * 2 * sizeof(int)); } while (arr == NULL);
	for (int i = 0; i < plus * 2; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < plus; i++)arr[i] += arr[i + plus];
	for (int i = 0; i < plus; i++) {
		printf("%d", arr[i]);
		if (i % a == a-1&&i!=plus-1)printf("\n");
		else printf(" ");
	}
	return 0;
}