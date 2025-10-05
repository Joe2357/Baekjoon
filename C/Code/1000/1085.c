#include <stdio.h>

#define min(a, b) (((a) > (b)) ? (b) : (a))

int main() {
	int x, y, w, h;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	printf("%d", min(min(x, w - x), min(y, h - y)));
	return 0;
}