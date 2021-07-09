#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef struct Node {
	int x, y;
} ND;

#define MAX_IDX 100
#define M 20000

const int INSIDE = 0;
const int CHEEZE = 1;
const int OUTSIDE = 2;

int grid[MAX_IDX + 2][MAX_IDX + 2];
ND dir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
ND stack[MAX_IDX * MAX_IDX];
int top = -1;
int n, m;
int left;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			scanf("%d", &grid[i][j]);
			left += grid[i][j];
		}
	}

	ND queue[M] = {{0, 0}};
	int front = 0, rear = 1;
	grid[0][0] = OUTSIDE;
	while (front < rear) {
		ND a = queue[front++];

		for (int i = 0; i < 4; ++i) {
			ND new = {a.x + dir[i].x, a.y + dir[i].y};
			if (new.x >= 0 && new.x <= n + 1 && new.y >= 0 && new.y <= m + 1) {
				if (grid[new.x][new.y] == INSIDE) {
					queue[rear++] = (ND){new.x, new.y};
					grid[new.x][new.y] = OUTSIDE;
				}
			}
		}
	}

	int result = 0;
	while (left > 0) {
		++result;

		/* melt section */
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (grid[i][j] == CHEEZE) {
					int a = 0;
					for (int k = 0; k < 4; ++k) {
						a += (grid[i + dir[k].x][j + dir[k].y] == OUTSIDE);
					}
					if (a >= 2) {
						stack[++top] = (ND){i, j};
						--left;
					}
				}
			}
		}

		while (top > -1) {
			ND b = stack[top--];
			grid[b.x][b.y] = OUTSIDE;
			front = 0, rear = 1;
			queue[0] = b;

			while (front < rear) {
				ND a = queue[front++];

				for (int i = 0; i < 4; ++i) {
					ND new = {a.x + dir[i].x, a.y + dir[i].y};
					if (grid[new.x][new.y] == INSIDE) {
						queue[rear++] = (ND){new.x, new.y};
						grid[new.x][new.y] = OUTSIDE;
					}
				}
			}
		}
		/* ------------ */
	}

	printf("%d", result);
	return 0;
}