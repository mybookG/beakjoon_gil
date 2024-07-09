#include <stdio.h>
#include <stdlib.h>

int main() {
	double Rounds = 0;
	long long Mean = 0;
	int number, data, Median=0, highest = -4001, smallest = 4001, check = 0;
	int mode[3] = { 0, };
	int modeCheck[8001] = { 0, };
    
	scanf("%d", &number);
	for (int i = 0; i < number; i++) {
		scanf("%d", &data);
		if (data > highest) 
			highest = data;
		if (data < smallest) 
			smallest = data;
		Mean += data;
		modeCheck[data + 4000]++;
	}

	Rounds = (double)Mean/number;
	Mean = (long long)(Rounds + (Rounds > 0 ? 0.5 : -0.5));

	for (int i = 0; i < 8001; i++) {
		if (modeCheck[i] > 0) {
			if (check < number/2 + 1) {
				check += modeCheck[i];
				if (check >= number / 2 + 1) Median = i - 4000;
			}

			if (mode[0] < modeCheck[i]) {
				mode[0] = modeCheck[i];
				mode[1] = 1;
				mode[2] = i - 4000;
			}
			else if ( (mode[0] == modeCheck[i]) && (mode[1] == 1)) {
				mode[1] = 2;
				mode[2] = i - 4000;
			}
		}
	}
	printf("%lld \n%d \n%d \n%d", Mean, Median, mode[2], highest - smallest);
	return 0;
}