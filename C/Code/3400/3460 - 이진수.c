#include <stdio.h>

int main(t) {
	for (scanf("%d", &t); t; t--) { // test case
		int temp, digit = 0;
		scanf("%d", &temp);
		while (temp) { // while temp > 0
			if (temp % 2)
				printf("%d ", digit); // print 1's position
			temp /= 2, digit++;
		}
	}
	return 0;
}