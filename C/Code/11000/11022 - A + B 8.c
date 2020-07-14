#include <stdio.h>

int main() {
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("Case #%d: %d + %d = %d\n", i + 1, a, b, a + b);
	}
	return 0;
}