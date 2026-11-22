#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef struct Position {
	int x, y;
} PS;

#define MAX_IDX 300
#define MAX_DIR 4
const int WATER = 0;

PS dir[MAX_DIR] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int grid[MAX_IDX][MAX_IDX];
int n, m;

#define max(a, b) (((a) > (b)) ? (a) : (b))

bool isValidPosition(PS p) {
	return (p.x >= 0 && p.x < n && p.y >= 0 && p.y < m);
}

bool isAllMelted() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (grid[i][j] != 0)
				return false;
		}
	}
	return true;
}

bool isSeperated() {
	bool hasIce = false;

	bool visit[MAX_IDX][MAX_IDX + 1] = {false};
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (grid[i][j] != WATER && !visit[i][j]) {
				if (hasIce == true) {
					return true;
				} else {
					hasIce = true;
				}

				PS q[MAX_IDX * MAX_IDX];
				int front = 0, rear = 0;

				visit[i][j] = true;
				q[rear++] = (PS){i, j};

				while (front < rear) {
					PS cur = q[front++];

					for (int d = 0; d < MAX_DIR; ++d) {
						PS new = {cur.x + dir[d].x, cur.y + dir[d].y};
						if (isValidPosition(new) == true) {
							if (grid[new.x][new.y] != WATER && !visit[new.x][new.y]) {
								visit[new.x][new.y] = true;
								q[rear++] = new;
							}
						}
					}
				}
			}
		}
	}
	return false;
}

void step() {
	int melt[MAX_IDX][MAX_IDX] = {0};

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (grid[i][j] != WATER) {
				for (int d = 0; d < MAX_DIR; ++d) {
					PS new = {i + dir[d].x, j + dir[d].y};
					if (isValidPosition(new) == true && grid[new.x][new.y] == WATER) {
						melt[i][j]++;
					}
				}
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			grid[i][j] = max(grid[i][j] - melt[i][j], 0);
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &grid[i][j]);
		}
	}

	int ret = 0;
	for (int i = 0; true; ++i) {
		if (isAllMelted() == true) {
			break;
		} else if (isSeperated() == true) {
			ret = i;
			break;
		} else {
			step();
		}
	}
	printf("%d", ret);
	return 0;
}