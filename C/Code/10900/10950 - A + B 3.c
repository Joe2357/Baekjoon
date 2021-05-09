#include <stdio.h>

int main() {
	int temp;
	scanf("%d", &temp);
	for (int i = 0; i < temp; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", a + b);
	}
	return 0;
}