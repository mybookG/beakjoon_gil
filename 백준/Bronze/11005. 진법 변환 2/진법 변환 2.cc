#include <stdio.h>

void check(int total,int number) {
	int a=0;
	if (total/number!=0) {
		check(total/number, number);
	}
	a = total % number;
	if (a >= 10) {
		printf("%c", a - 10 + 'A');
	}
	else printf("%d", a);
}

int main() {
	int number,total;
	scanf("%d %d", &total,&number);
	check(total, number);
	return 0;
}