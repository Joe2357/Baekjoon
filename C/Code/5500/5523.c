#include <stdio.h>

int main() {
	int win_a = 0, win_b = 0;
	int n;
	scanf("%d", &n);
	while (n--) {
		int a, b;
		scanf("%d %d", &a, &b);
		win_a += (a > b), win_b += (a < b);
	}
	printf("%d %d", win_a, win_b);
	return 0;
}