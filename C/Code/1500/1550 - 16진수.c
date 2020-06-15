#include <stdio.h>

int main() {
	char str[10];
	scanf("%s", str);									// input string
	int result = 0;
	for (int i = 0; str[i]; i++) {
		result *= 16;									// 'A0' = 'A' * 16 
		result += str[i] - 48 - 7 * (str[i] >= 'A');	// 'B' -> 11, '6' -> 6
	}
	printf("%d", result);
	return 0;
}