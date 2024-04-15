#include <stdio.h>

int main() {
	int a, c = 2;
	scanf("%d", &a);
	for (int i = 0; i < a; i++) c += (c - 1);
	printf("%d", c * c);
	return 0;
}