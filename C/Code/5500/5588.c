#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

const int LEQ = 1;
const int REQ = -1;
const int EQ = 0;

typedef struct Position {
	int x, y;
} PS;

#define MAX_IDX 1000
const int NONE = 123456789;

PS zodiac[MAX_IDX];
PS star[MAX_IDX];

int cmp(PS* a, PS* b) {
	if (a->x > b->x || (a->x == b->x && a->y > b->y)) {
		return 1;
	} else if (a->x < b->x || (a->x == b->x && a->y < b->y)) {
		return -1;
	} else {
		return 0;
	}
}

int cmp_with_tx_ty(PS* a, PS* b, int tx, int ty) {
	int ret;
	if (a->x > (b->x + tx)) {
		ret = LEQ;
	} else if (a->x < (b->x + tx)) {
		ret = REQ;
	} else if (a->x == (b->x + tx) && a->y > (b->y + ty)) {
		ret = LEQ;
	} else if (a->x == (b->x + tx) && a->y < (b->y + ty)) {
		ret = REQ;
	} else {
		ret = EQ;
	}

	return ret;
}
int find(PS* s, int l, int r, int tx, int ty) {
	while (l <= r) {
		int mid = (l + r) / 2;
		int ret_cmp = cmp_with_tx_ty(&star[mid], s, tx, ty);

		if (ret_cmp == EQ) {
			return mid;
		} else if (ret_cmp == LEQ) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}

	return NONE;
}

int main() {
	int n, m;
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		zodiac[i] = (PS){a, b};
	}
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		star[i] = (PS){a, b};
	}

	qsort(zodiac, m, sizeof(PS), cmp);
	qsort(star, n, sizeof(PS), cmp);

	for (int i = 0; i < n - m; ++i) {
		int tx = star[i].x - zodiac[0].x, ty = star[i].y - zodiac[0].y;
		bool isThisAnswer = true;

		int cur = i + 1;
		for (int j = 1; j < m; ++j) {
			cur = find(&zodiac[j], cur, n - 1, tx, ty);

			if (cur == NONE) {
				isThisAnswer = false;
				break;
			}
		}

		if (isThisAnswer == true) {
			printf("%d %d", tx, ty);
			return 0;
		}
	}

	return 0;
}