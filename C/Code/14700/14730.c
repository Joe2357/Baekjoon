#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	int sum = 0;
	while (n--) {
		int c, k;
		scanf("%d %d", &c, &k);
		sum += (c * k);
	}
	printf("%d", sum);
	return 0;
}