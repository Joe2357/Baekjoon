#include <stdio.h>

int main() {
	int n;
	int result = 0, temp = 100000000, a = 9;
	for (scanf("%d", &n); n; n--) {
		while (n < temp)
			temp /= 10, a--;
		result += a;
	}
	printf("%d", result);
	return 0;
}