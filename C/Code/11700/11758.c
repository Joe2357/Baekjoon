#include <stdio.h>

typedef struct Node {
	int x, y;
} ND;

int ccw(ND a, ND b, ND c) {
	int t1 = (a.x * b.y + b.x * c.y + c.x * a.y);
	int t2 = (b.x * a.y + c.x * b.y + a.x * c.y);

	if (t1 - t2 > 0) {
		return 1;
	} else if (t1 - t2 < 0) {
		return -1;
	} else {
		return 0;
	}
}

int main() {
	int x1, y1;
	int x2, y2;
	int x3, y3;

	scanf("%d %d", &x1, &y1);
	scanf("%d %d", &x2, &y2);
	scanf("%d %d", &x3, &y3);

	ND a = (ND){x1, y1}, b = (ND){x2, y2}, c = (ND){x3, y3};

	printf("%d", ccw(a, b, c));
	return 0;
}