#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int sum = 0;
		while (n--) {
			int x;
			scanf("%d", &x);
			sum += x;
		}
		printf("%d\n", sum);
	}
	return 0;
}