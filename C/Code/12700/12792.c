#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int j;
		scanf("%d", &j);
		if (j == i) {
			printf("-1");
			return 0;
		}
	}
	printf("1000003");
	return 0;
}