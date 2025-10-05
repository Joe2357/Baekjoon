#include <stdio.h>

#define MAX_LEN 80

char str[MAX_LEN + 1];
int error_idx;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %s", &error_idx, str);
		str[error_idx - 1] = '\0';
		printf("%s%s\n", str, &str[error_idx]);
	}
	return 0;
}