#include<stdio.h>
int main() {
	int chi=0, cok = 0, beer = 0, total = 0;
	scanf("%d\n%d %d", &chi, &cok, &beer);
	total = cok / 2 + beer;
	if (total > chi)printf("%d", chi);
	else printf("%d", total);

}