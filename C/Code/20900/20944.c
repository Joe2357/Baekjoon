#include <stdio.h>

#define MAX_LEN (int)(1e6)

char str[MAX_LEN + 1];
int n;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		str[i] = 'a';
	}
	printf("%s", str);
	return 0;
}