#include <stdio.h>

#define MAX_LEN 100

char str[MAX_LEN + 1];

int main() {
	scanf("%s", str);

	for (int i = 0; str[i] != '\0'; ++i) {
		if ('A' <= str[i] && str[i] <= 'Z') {
			str[i] += ('a' - 'A');
		} else if ('a' <= str[i] && str[i] <= 'z') {
			str[i] += ('A' - 'a');
		}
	}
	printf("%s", str);
	return 0;
}