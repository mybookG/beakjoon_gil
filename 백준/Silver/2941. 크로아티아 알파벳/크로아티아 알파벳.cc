#include <stdio.h>
#include <string.h>

int Check(char* arr, char* scan, int i) {
	for (int j = 0; j < i; j++) {
		if (*(arr + j) != *(scan + j)) {
			return(0);
		}
	}
	for (int j = 0; j < i; j++) *(scan + j) = '0';
	return (i - 1);
}
int main() {
	char arr[8][4] = { "c=","c-","dz=","d-","lj","nj","s=","z=" };
	char scan[101];
	scanf("%s", scan);
	int len = strlen(scan), total = len;
	for (int A = 0; A < 8; A++) {
		for (int i = 0; i < len; i++) {
			if (scan[i] == arr[A][0]) {
				total -= Check(arr[A], &scan[i], strlen(arr[A]));
			}
		}
	}
	printf("%d", total);
}