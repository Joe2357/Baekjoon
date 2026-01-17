#include <stdio.h>

typedef struct Node {
	int x, y, z;
	int day;
} ND;

#define WALL -1
#define UNRIPE 0
#define RIPE 1

#define MAX_IDX 100
int grid[MAX_IDX][MAX_IDX][MAX_IDX];
int m, n, h;

ND dir[6] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {-1, 0, 0}, {0, -1, 0}, {0, 0, -1}};
ND q[MAX_IDX * MAX_IDX * MAX_IDX];
int f, r;

int main() {
	scanf("%d %d %d", &m, &n, &h);
	int unripeCount = 0;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < m; ++k) {
				scanf("%d", &grid[i][j][k]);
				if (grid[i][j][k] == UNRIPE) {
					++unripeCount;
				} else if (grid[i][j][k] == RIPE) {
					q[r++] = (ND){i, j, k, 0};
				}
			}
		}
	}

	int retval = 0;
	while (f < r) {
		ND cur = q[f++];
		retval = cur.day;

		for (int i = 0; i < 6; ++i) {
			ND new = (ND){cur.x + dir[i].x, cur.y + dir[i].y, cur.z + dir[i].z, cur.day + 1};
			if (0 <= new.x && new.x < h && 0 <= new.y && new.y < n && 0 <= new.z && new.z < m) {
				if (grid[new.x][new.y][new.z] == UNRIPE) {
					--unripeCount;
					grid[new.x][new.y][new.z] = RIPE;
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