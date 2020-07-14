#include <stdio.h>
#define pow(x) x * x 	// pow(x) = x ^ 2

int main() {
	int result = 0;
	for (int i = 0; i < 5; i++) {
		int temp;
		scanf("%d", &temp);
		result += pow(temp);		// add all x^2
	}
	printf("%d", result % 10);		// modulo 10
	return 0;
}