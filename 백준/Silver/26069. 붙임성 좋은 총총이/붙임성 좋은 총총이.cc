#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
int check(char* che,char** arr,int check) {
	for (int j = 0; j <= check; j++) 
		if (!strcmp(che, arr[j])) 
			return 1;
	return 0;
}

int main() {
	int N,insert=0,firCheck,secCheck;
	char fir[21], sec[21];
	scanf("%d", &N);
	char** arr = (char**)malloc(sizeof(char*) * N);
	arr[0] = (char*)malloc(sizeof(char) * 21);
	strcpy(arr[0], "ChongChong");
	for (int i = 0; i < N; i++) {
		scanf("%s", fir,21);
		scanf("%s", sec, 21);
		firCheck = check(fir, arr, insert);
		secCheck = check(sec, arr, insert);
		if (firCheck && !secCheck) {
			insert++;
			arr[insert] = (char*)malloc(sizeof(char) * 21);
			strcpy(arr[insert], sec);
		}
		else if (!firCheck && secCheck) {
			insert++;
			arr[insert] = (char*)malloc(sizeof(char) * 21);
			strcpy(arr[insert], fir);
		}
	}
	printf("%d", insert + 1);
}