#include <stdio.h>

int main() {
	int ret = 0;

	int n;
	scanf("%d", &n);
	while (n--) {
		int a, b;
		scanf("%d %d", &a, &b);
		ret += (b % a);
	}

	printf("%d", ret);
	return 0;
}