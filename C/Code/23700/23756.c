#include <stdio.h>

const int MAX_ANGLE = 360;

#define abs(x) ((x) < 0 ? -(x) : (x))
#define min(a, b) ((a) < (b) ? (a) : (b))

int main() {
	int n, a;
	scanf("%d %d", &n, &a);

	int ret = 0;
	while (n--) {
		int angle;
		scanf("%d", &angle);
		ret += min(abs(angle - a), MAX_ANGLE - abs(angle - a));
		a = angle;
	}
	printf("%d", ret);
	return 0;
}