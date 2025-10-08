#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef long long ll;
typedef struct Node {
	int x, y;
} ND;

#define MAX_IDX 9
const ll DIGIT = 10LL;
const ll NONE = -1LL;

char grid[MAX_IDX][MAX_IDX + 1];
int n, m;
ll retval = NONE;

#define max(a, b) (((a) > (b)) ? (a) : (b))

bool isVaildPosition(ND cur) {
	return ((0 <= cur.x && cur.x < n) && (0 <= cur.y && cur.y < m));
}

bool isSquareInteger(ll x) {
	for (ll i = 0LL; i * i <= x; ++i) {
		if (i * i == x) {
			return true;
		}
	}
	return false;
}

void getSubProblem(ND cur, ND move) {
	for (ll newInt = 0LL; isVaildPosition(cur) == true; cur.x += move.x, cur.y += move.y) {
		newInt *= DIGIT, newInt += (grid[cur.x][cur.y] - '0');
		if (isSquareInteger(newInt) == true) {
			retval = max(retval, newInt);
		}
	}
	return;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%s", grid[i]);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {						// 시작점 (i, j)
			for (int k = -MAX_IDX; k <= MAX_IDX; ++k) {		// x 방향 이동
				for (int l = -MAX_IDX; l <= MAX_IDX; ++l) { // y 방향 이동
					if (k != 0 || l != 0) {
						getSubProblem((ND){i, j}, (ND){k, l});
					}
				}
			}
		}
	}

	printf("%d", retval);
	return 0;
}