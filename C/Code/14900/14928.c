#include <stdio.h>

#define MAX_LEN (int)(1e6)

char str[MAX_LEN + 1];
const int MOD = 20000303;
const int DIGIT = 10;

int main() {
	scanf("%s", str);

	int ret = 0;
	for (int i = 0; str[i] != '\0'; ++i) {
		ret = (ret * DIGIT + (str[i] - '0')) % MOD;
	}
	printf("%d", ret);
	return 0;
}