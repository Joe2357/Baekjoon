#include <stdio.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int main() {
	int l, r, k;
	scanf("%d %d %d", &l, &r, &k);
	switch (k) {
		case 2: {
			printf("%d", max(r / 1 - (max(l, 3) - 1) / 1, 0));
			break;
		}
		case 3: {
			printf("%d", max(r / 3 - (max(l, 6) - 1) / 3, 0));
			break;
		}
		case 4: {
			printf("%d", max(r / 2 - (max(l, 14) - 1) / 2, 0) + (l <= 10 && r >= 10));
			break;
		}
		case 5: {
			printf("%d", max(r / 5 - (max(l, 15) - 1) / 5, 0));
			break;
		}
	}
	return 0;
}