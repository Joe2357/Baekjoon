#include <stdio.h>

#define MAX_LEN 100

char str[MAX_LEN + 1];

int main() {
	scanf("%s", str);

	int ret = 1;
	for (int i = 0; str[i] != '\0'; ++i) {
		ret += (str[i] == ',');
	}
	printf("%d", ret);
	return 0;
}