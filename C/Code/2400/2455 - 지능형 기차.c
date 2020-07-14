#include <stdio.h>
#define max(a, b) (a > b) ? a : b

int main() {
	int person = 0, result = 0;
	for (int i = 0; i < 4; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		person += (b - a);	// calculate person's amount
		result = max(result, person);
	}
	printf("%d", result);
	return 0;
}