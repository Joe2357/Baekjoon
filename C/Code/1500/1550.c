#include <stdio.h>

#define HEX_MAX_LEN 6
const int HEX_DIGIT = 16;

char str[HEX_MAX_LEN + 1];

int main() {
	scanf("%s", str);

	int result = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		result *= HEX_DIGIT; // 'A0' = 'A' * 16

		if ('A' <= str[i] && str[i] <= 'F') {
			result += (str[i] - 'F' - 1 + HEX_DIGIT);
		} else {
			result += (str[i] - '0');
		}
	}
	printf("%d", result);
	return 0;
}