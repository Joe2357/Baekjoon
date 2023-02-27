#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef struct ND {
	int x, y;
} ND;
const int North = 0;
const int East = 1;
const int South = 2;
const int West = 3;
ND dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

#define EMPTY 0
#define WALL 1
#define CLEANED 2
#define MAX_IDX 50
bool grid[MAX_IDX][MAX_IDX];
int n, m;
int r, c, d;
int retval;

void clean(int x, int y) {
	if (grid[x][y] == EMPTY) {
		grid[x][y] = CLEANED;
		++retval;
	}
	return;
}

int main() {
	scanf("%d %d", &n, &m);
	scanf("%d %d %d", &r, &c, &d);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &grid[i][j]);
		}
	}

	bool notExit = true;
	while (notExit == true) {
		clean(r, c);

		int directionStack = 0;
		bool allCleaned = true;

		for (int directionStack = 1; directionStack <= 4; ++directionStack) {
			int curD = ((d - directionStack) + 8) % 4;
			if (grid[r + dir[curD].x][c + dir[curD].y] == EMPTY) {
				allCleaned = false;
				d = curD;
				r += dir[curD].x, c += dir[curD].y;	 // move forward
				break;
			}
		}

		if (allCleaned == true) {
			int backD = ((d - 2) + 8) % 4;
			if (grid[r + dir[backD].x][c + dir[backD].y] == WALL) {
				notExit = false;
			} else {
				r += dir[backD].x, c += dir[backD].y;
			}
		}
	}

	printf("%d", retval);
	return 0;
}