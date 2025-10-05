#include <stdio.h>

#define MAX_LEN 60

char input[MAX_LEN + 1 + 1];

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		scanf("%s", input);
		int len = 0;

		for (len = 0; input[len] != '\0'; ++len) {
		}
		printf("%s\n", ((input[--len] - '0') % 2 == 0) ? "even" : "odd");
	}

	return 0;
}