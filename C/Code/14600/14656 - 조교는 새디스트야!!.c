#include <stdio.h>

int main() {
	int n, result = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		if (temp - 1 != i)
			result++;
	}
	printf("%d", result);
	return 0;
}