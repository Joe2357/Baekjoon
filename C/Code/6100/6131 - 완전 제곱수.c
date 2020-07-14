#include <stdio.h>

int main(n) {
	scanf("%d", &n);
	int result = 0;
	for (int a = 1, b = 1; a < 500;)
		if (a * a - b * b > n)
			b++;
		else if (a * a - b * b < n)
			a++;
		else
			result++, a++, b++;
	printf("%d", result);
	return 0;
}