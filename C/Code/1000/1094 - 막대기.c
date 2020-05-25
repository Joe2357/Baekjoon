#include <stdio.h>

int main() {
	int x, result = 0, temp = 64;
	for(scanf("%d", &x); x;) {
		if (x >= temp)
			result++, x -= temp;	// discard target part
		else
			temp /= 2;				// discard one of half
	}
	printf("%d", result);
	return 0;
}