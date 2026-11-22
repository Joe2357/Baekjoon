#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef long long ll;
typedef struct Node {
	ll x, y;
} ND;

int ccw(ND a, ND b, ND c) {
	ll t1 = (a.x * b.y + b.x * c.y + c.x * a.y);
	ll t2 = (b.x * a.y + c.x * b.y + a.x * c.y);

	if (t1 - t2 > 0) {
		return 1;
	} else if (t1 - t2 < 0) {
		return -1;
	} else {
		return 0;
	}
}

bool isLeftPointBigger(ND a, ND b) {
	return (a.x > b.x || (a.x == b.x && a.y >= b.y));
}

void swap(ND* a, ND* b) {
	ND temp = *a;
	*a = *b, *b = temp;
	return;
}

bool isIntersect(ND a, ND b, ND c, ND d) {
	int c1 = ccw(a, b, c), c2 = ccw(a, b, d);
	int c3 = ccw(c, d, a), c4 = ccw(c, d, b);

	if (c1 * c2 <= 0 && c3 * c4 <= 0) {
		if (c1 * c2 == 0 && c3 * c4 == 0) {
			if (isLeftPointBigger(a, b)) {
				swap(&a, &b);
			}
			if (isLeftPointBigger(c, d)) {
				swap(&c, &d);
			}

			return (isLeftPointBigger(d, a) && isLeftPointBigger(b, c));
		} else {
			return true;
		}
	} else {
		return false;
	}
}

int main() {
	ll x1, y1, x2, y2;
	ll x3, y3, x4, y4;
	scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
	scanf("%lld %lld %lld %lld", &x3, &y3, &x4, &y4);

	ND a = (ND){x1, y1}, b = (ND){x2, y2}, c = (ND){x3, y3}, d = (ND){x4, y4};

	printf("%d", isIntersect(a, b, c, d));
	return 0;
}