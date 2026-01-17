#include <stdio.h>

#define INF (int)(2e9 + 1)

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int main() {
	int max_y = -INF, min_y = INF;

	int n;
	scanf("%d", &n);
	while (n--) {
		int x, y;
		scanf("%d %d", &x, &y);
		max_y = max(max_y, y);
		min_y = min(min_y, y);
	}

	printf("%d", max_y - min_y);
	return 0;
}