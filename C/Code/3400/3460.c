#include <stdio.h>

int main(t) {
	scanf("%d", &t);
	for (; t; t--) {
		int temp, digit = 0;
		scanf("%d", &temp);
		while (temp) {
			if (temp % 2)
				printf("%d ", digit);
			temp /= 2, digit++;
		}
	}
	return 0;
}