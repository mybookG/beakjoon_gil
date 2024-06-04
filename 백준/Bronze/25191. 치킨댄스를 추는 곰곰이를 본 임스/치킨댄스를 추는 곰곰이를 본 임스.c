#include<stdio.h>
int main() {
	int chi,cok,beer;
	scanf("%d\n%d %d", &chi, &cok, &beer);
	cok / 2 + beer > chi ? printf("%d", chi) : printf("%d", cok / 2 + beer);
}