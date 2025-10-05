#include <stdio.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) > (b)) ? (b) : (a))

const int INF = 987654321;

int min_x, max_x;
int min_y, max_y;

void init() {
	min_x = min_y = INF;
	max_x = max_y = -INF;
	return;
}

int main() {
	init();

	int n;
	scanf("%d", &n);
	while (n--) {
		int x, y;
		scanf("%d %d", &x, &y);

		min_x = min(min_x, x), max_x = max(max_x, x);
		min_y = min(min_y, y), max_y = max(max_y, y);
	}
	printf("%d", (max_x - min_x) * (max_y - min_y));
	return 0;
}