#include <stdio.h>

int main(n) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {				// brute force
		int temp = i, result = i;				// result = i's constructor
		while (temp)
			result += temp % 10, temp /= 10;	// result += all digits of i
		if (result == n) {						// if i is constructor of n
			printf("%d", i);
			return 0;
		}
	}
	printf("0");								// no constructor
	return 0;
}