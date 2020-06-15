#include <stdio.h>

int main(n) {
	int day = 0, temp = 1;
	for (scanf("%d", &n); n; n -= temp++, day++)	// birds reducing, day increasing
		if (n < temp)								// if there are no birds more than temp
			temp = 1;								// reset temp
	printf("%d", day);
	return 0;
}