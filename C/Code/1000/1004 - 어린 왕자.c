#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int retval = 0;

		// start, end position
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		// planetary
		int n;
		scanf("%d", &n);
		while (n--) {
			int cx, cy, r;
			scanf("%d %d %d", &cx, &cy, &r);

			bool startInCircle = ((x1 - cx) * (x1 - cx) + (y1 - cy) * (y1 - cy)) < (r * r);
			bool endInCircle = ((x2 - cx) * (x2 - cx) + (y2 - cy) * (y2 - cy)) < (r * r);
			if (startInCircle ^ endInCircle) {
				++retval;
			}
		}

		printf("%d\n", retval);
	}
}