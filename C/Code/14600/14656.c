#include <stdio.h>

int main() {
	int n, result = 0;
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i) {
		int temp;
		scanf("%d", &temp);
		result += (temp != i);
	}
	printf("%d", result);
	return 0;
}