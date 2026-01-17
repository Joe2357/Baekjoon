#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_LEN 10

char str[MAX_LEN + 1];
int n;

int main() {
	scanf("%d %s", &n, str);
	for (int i = 0; i <= n - 4; ++i) {
		if (str[i] == 'g' && str[i + 1] == 'o' && str[i + 2] == 'r' && str[i + 3] == 'i') {
			printf("YES");
			return 0;
		}
	}
	printf("NO");
	return 0;
}