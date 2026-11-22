#include <stdio.h>

#define min(a, b) (((a) > (b)) ? (b) : (a))

int main() {
	int y, c, p;
	scanf("%d %d %d", &y, &c, &p);
	printf("%d", min(y, min(c / 2, p)));
	return 0;
}