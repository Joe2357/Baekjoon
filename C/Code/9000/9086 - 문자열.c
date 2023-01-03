#include <stdio.h>

#define MAX_LEN 1001

char str[MAX_LEN];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%s", str);
		int i = 0;
		while (str[i] != '\0') {
			++i;
		}
		printf("%c%c\n", str[0], str[--i]);
	}
	return 0;
}