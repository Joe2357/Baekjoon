#include <stdio.h>

int main(n, temp) {
	scanf("%d", &n);
	do {
		scanf("%d", &temp);
		if (!temp)  // end program
			return 0;
		else if (temp % n)  // can't divide
			printf("%d is NOT a multiple of %d.\n", temp, n);
		else    // can divide
			printf("%d is a multiple of %d.\n", temp, n);
	} while (temp); // loop while input is not 0
}