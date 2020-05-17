#include <stdio.h>
#define POW(a) (a) * (a)	// a ^ 2

int main(t, x1, y1, r1, x2, y2, r2) {
	for (scanf("%d", &t); t; t--) {
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		if ((x1 == x2) && (y1 == y2)) {			// center of circle is same
			printf("%d\n", -1 * (r1 == r2));	// print whether radius is same or not
			continue;
		}
		int dist = POW(x1 - x2) + POW(y1 - y2);	// distance in 2 circles
		if (dist > POW(r1 + r2))
			printf("0\n");
		else if (dist == POW(r1 + r2))
			printf("1\n");
		else if (dist > POW(r1 - r2))
			printf("2\n");
		else if (dist == POW(r1 - r2))
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}