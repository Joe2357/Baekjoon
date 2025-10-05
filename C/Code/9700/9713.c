#include <math.h>
#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		n = (n + 1) / 2;
		printf("%d\n", n * n);
	}
	return 0;
}