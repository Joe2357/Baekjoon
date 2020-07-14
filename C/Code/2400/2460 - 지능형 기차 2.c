#include <stdio.h>
#define max(a, b) (a > b) ? a : b

int main() {
	int people = 0, result = -1;
	for (int i = 0; i < 10; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		people += (b - a);				// current people count
		result = max(result, people);	// finding max value
	}
	printf("%d", result);
	return 0;
}