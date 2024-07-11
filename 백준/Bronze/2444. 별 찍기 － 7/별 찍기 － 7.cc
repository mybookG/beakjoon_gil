#include <stdio.h>
#include <stdlib.h>

int main() {
	int total, scan = 0;
	scanf("%d", &scan);
	for (int i = 1; i < 2 * scan; i++) {
		for (int j = 1; j < 2 * scan; j++) {
			total = abs(scan - i);
			if (j > 2 * scan - total)break;
			if (total < j && j < 2 * scan - total)printf("*");
			else printf(" ");
		}
		if (i < 2 * scan - 1)printf("\n");
	}
	return 0;
}