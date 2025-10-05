#include <stdio.h>

#define MAX_LEN 1000

char number[MAX_LEN];
int b;

int main() {
	scanf("%s %d", number, &b);

	int ret = 0;
	for (int i = 0; number[i] != '\0'; ++i) {
		ret *= b;

		if ('0' <= number[i] && number[i] <= '9') {
			ret += (number[i] - '0');
		} else {
			ret += (number[i] - 'A' + 10);
		}
	}
	printf("%d", ret);
	return 0;
}