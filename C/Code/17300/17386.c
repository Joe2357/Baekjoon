#include <stdio.h>

typedef long long ll;
typedef struct Node {
	ll x, y;
} ND;

ll ccw(ND a, ND b, ND c) {
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

int main() {
	ll x1, y1, x2, y2;
	ll x3, y3, x4, y4;
	scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
	scanf("%lld %lld %lld %lld", &x3, &y3, &x4, &y4);

	ND a = (ND){x1, y1}, b = (ND){x2, y2}, c = (ND){x3, y3}, d = (ND){x4, y4};

	printf("%d", ((ccw(a, b, c) * ccw(a, b, d) < 0) && (ccw(c, d, a) * ccw(c, d, b) < 0)));
	return 0;
}