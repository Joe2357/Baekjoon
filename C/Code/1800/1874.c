#include <stdio.h>

#define M (int)(1e5)

char str[2 * M + 1];
int sl;
int stack[M], len;
int n, c;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);

		if (len != 0 && stack[len - 1] > a) {
			printf("NO");
			return 0;
		}

		while (c < a) {
			stack[len++] = ++c;
			str[sl++] = '+';
		}

		if (len == 0 || stack[len - 1] != a) {
			printf("NO");
			return 0;
		} else {
			str[sl++] = '-';
			--len;
		}
	}

	for (int i = 0; i < sl; ++i) {
		printf("%c\n", str[i]);
	}
	return 0;
}