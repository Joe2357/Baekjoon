#include <stdio.h>

int main(n, temp) {
	scanf("%d", &n);
	do {
		scanf("%d", &temp);
		if (temp == 0)
			return 0;
		else if (temp % n > 0)
			printf("%d is NOT a multiple of %d.\n", temp, n);
		else
			printf("%d is a multiple of %d.\n", temp, n);
	} while (temp != 0);
}