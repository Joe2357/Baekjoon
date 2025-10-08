#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int x1, y1, r1, x2, y2, r2;
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

		if (x1 == x2 && y1 == y2) { // if same center
			if (r1 == r2) {			// case 1. exactly same circle
				printf("-1\n");
			} else { // case 2. no crossing point
				printf("0\n");
			}
		} else { // if not same center
			int distPow2 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);

			if (distPow2 > (r1 + r2) * (r1 + r2)) { // case 3
				printf("0\n");
			} else if (distPow2 == (r1 + r2) * (r1 + r2)) { // case 4
				printf("1\n");
			} else if (distPow2 > (r1 - r2) * (r1 - r2)) { // case 5
				printf("2\n");
			} else if (distPow2 == (r1 - r2) * (r1 - r2)) { // case 6
				printf("1\n");
			} else { // case 7
				printf("0\n");
			}
		}
	}

	return 0;
}