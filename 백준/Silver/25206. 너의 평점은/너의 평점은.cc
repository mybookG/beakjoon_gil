#include <stdio.h>
#include <string.h>
float Check(float sc,char* abc) {
	float hack=0.0;
	if (!strcmp(abc,"A+"))hack = 4.5;
	else if (!strcmp(abc,"A0"))hack = 4.0;
	else if (!strcmp(abc, "B+"))hack = 3.5;
	else if (!strcmp(abc, "B0"))hack = 3.0;
	else if (!strcmp(abc, "C+"))hack = 2.5;
	else if (!strcmp(abc, "C0"))hack = 2.0;
	else if (!strcmp(abc, "D+"))hack = 1.5;
	else if (!strcmp(abc, "D0"))hack = 1.0;
	return(sc * hack);
	
}

int main() {
	char scan[51], abc[3];
	float total=0.0, sc;
	float alltotal=0.0;
	for (int i = 0; i < 20; i++) {
		scanf("%s", scan);
		scanf("%f", &sc);
		scanf("%s", abc);
		if(!strcmp(abc,"P"))continue;
		alltotal +=sc;
		total += Check(sc,abc);
    }
	printf("%.5f", total/alltotal);
}