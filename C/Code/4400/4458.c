#include <stdio.h>

#define MAX_LEN 30

char str[MAX_LEN + 1];

int main() {
	int t;
	scanf("%d ", &t);
	while (t--) {
		gets(str);
		if ('a' <= str[0] && str[0] <= 'z') {
			str[0] -= 'a', str[0] += 'A';
		}
		printf("%s\n", str);
	}
	return 0;
}