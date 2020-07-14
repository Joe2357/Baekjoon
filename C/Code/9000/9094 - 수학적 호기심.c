#include <stdio.h>

int main(t) {
	for (scanf("%d", &t); t; t--) {
		int n, m, result = 0;
		scanf("%d %d", &n, &m);
		for (int a = 1; a < n; a++)
			for (int b = a + 1; b < n; b++) {
				int temp = a * a + b * b + m;
				result += !(temp % (a * b)); // 1 if moduler is 0, else 0
			}
		printf("%d\n", result);
	}
	return 0;
}