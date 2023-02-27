#include <math.h>  // sqrt
#include <stdio.h>

typedef long long ll;
typedef char bool;
const bool true = 1;
const bool false = 0;
typedef struct Node {
	int x, y;
} ND;

#define MAX_IDX 9
char grid[MAX_IDX][MAX_IDX + 1];
int n, m;
ll retval = -1;

#define max(a, b) (((a) > (b)) ? (a) : (b))

bool isVaildPosition(ND cur) {
	return ((0 <= cur.x && cur.x < n) && (0 <= cur.y && cur.y < m));
}

bool isSquareInteger(ll x) {
	ll a = (ll)sqrt(x);
	return (a * a == x);
}
void getSubProblem(ND cur, ND move) {
	ll newInt = 0;
	while (isVaildPosition(cur) == true) {
		newInt *= 10, newInt += (grid[cur.x][cur.y] - '0');
		cur.x += move.x, cur.y += move.y;

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
		for (int j = 0; j < m; ++j) {  // start point

			for (int k = -MAX_IDX; k <= MAX_IDX; ++k) {	 // brute force
				for (int l = -MAX_IDX; l <= MAX_IDX; ++l) {
					if (k == 0 && l == 0) {
						continue;
					}
					getSubProblem((ND){i, j}, (ND){k, l});
				}
			}
		}
	}

	printf("%d", retval);
	return 0;
}