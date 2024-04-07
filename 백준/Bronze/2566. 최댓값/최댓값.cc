#include <stdio.h>

int main() {
	int max=0 , max_loction=0;
	int arr[81];
	for (int i = 0; i < 81; i++)scanf("%d", &arr[i]);
	for (int i = 0; i < 81; i++) {
		if (max < arr[i]) {
			max = arr[i];
			max_loction = i;
		}
	}
	printf("%d\n%d %d", max, max_loction / 9 + 1, max_loction % 9 + 1);
	return 0;
}