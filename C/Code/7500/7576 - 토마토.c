#include <stdio.h>

typedef struct Node {
	int x, y;
	int day;
} ND;

#define WALL -1
#define UNRIPE 0
#define RIPE 1

#define MAX_IDX 1000
int n, m;
int grid[MAX_IDX][MAX_IDX];

ND dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
ND q[MAX_IDX * MAX_IDX];
int f, r;

int main() {
	scanf("%d %d", &n, &m);
	int unripeCount = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &grid[i][j]);
			if (grid[i][j] == UNRIPE) {
				++unripeCount;
			} else if (grid[i][j] == RIPE) {
				q[r++] = (ND){i, j, 0};
			}
		}
	}

	int retval = 0;
	while (f < r) {
		ND cur = q[f++];
		retval = cur.day;
		
		for (int i = 0; i < 4; ++i) {
			ND new = (ND){cur.x + dir[i].x, cur.y + dir[i].y, cur.day + 1};
			if (0 <= new.x&& new.x < m && 0 <= new.y&& new.y < n) {
				if (grid[new.x][new.y] == UNRIPE) {
					--unripeCount;
					grid[new.x][new.y] = RIPE;
					q[r++] = new;
				}
			}
		}
	}

	if (unripeCount == 0) {
		printf("%d", retval);
	} else {
		printf("-1");
	}
	return 0;
}