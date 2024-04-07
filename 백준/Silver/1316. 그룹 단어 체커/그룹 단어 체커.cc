#include <stdio.h>
#include <string.h>
int Check(char *scan,int len) {
	for (int i = 0; i < len; i++) {
		int che = 0;
		for (int j = i + 1; j < len; j++) {
			if (scan[i] == scan[j] && che == 1) return 0;
			else if (scan[i] != scan[j]) che = 1;
		}
	}
	return 1;
}

int main() {
	int total = 0, re,che=0;
	char scan[101];
	scanf("%d", &re);
	for (int i = 0; i < re; i++) {
		scanf("%s", scan);
		int len = strlen(scan);
		total += Check(scan, len);
	}
	printf("%d", total);
	
	return 0;
}