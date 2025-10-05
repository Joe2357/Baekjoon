#include <stdio.h>

#define MAX_LEN 50
const int SAME = 5;
const int DIFF = 10;

char str[MAX_LEN + 1];

int main() {
	scanf("%s", str);

	char c = '\0';
	int ret = 0;
	for (int i = 0; str[i] != '\0'; ++i) {
		ret += ((str[i] == c) ? SAME : DIFF);
		c = str[i];
	}
	printf("%d", ret);
	return 0;
}