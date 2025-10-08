#include <stdio.h>

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		int len = 1;
		for (int mod = 1; mod % n != 0; ++len) {
			mod = (mod * 10 + 1) % n;
		}
		printf("%d\n", len);
	}
	return 0;
}