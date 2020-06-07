#include <stdio.h>

int main(a, b) {
	scanf("%d %d", &a, &b);
	int result = 0, count = 1, temp = 1;
	for (int i = 1; i <= b; i++) {
		if (--a < 1)						// start point
			result += count;
		if (!--temp)						// if count = 2, temp = 3 ( next count will be 3, and it will appear 3 times )
			temp = ++count;
	}
	printf("%d", result);
	return 0;
}