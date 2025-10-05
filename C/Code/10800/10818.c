#include <stdio.h>

const int INF = 987654321;

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

int main() {
	int min_v = INF, max_v = -INF;

	int n;
	scanf("%d", &n);
	while (n--) {
		int temp;
		scanf("%d", &temp);
		min_v = min(min_v, temp), max_v = max(max_v, temp);
	}
	printf("%d %d", min_v, max_v);
	return 0;
}