#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;
typedef struct Node {
	int x, y;
} ND;

#define RED 'R'
#define BLUE 'B'
#define GREEN 'G'

#define MAX_IDX 100
char grid[MAX_IDX][MAX_IDX + 1];
bool visit[MAX_IDX][MAX_IDX] = {false};
int n;
ND dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void init() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			visit[i][j] = false;
		}
	}
	return;
}

void wrap(int x, int y, int mark, bool blind) {
	for (int i = 0; i < 4; ++i) {
		ND cur = (ND){x + dir[i].x, y + dir[i].y};
		if (0 <= cur.x && cur.x < n && 0 <= cur.y && cur.y < n && visit[cur.x][cur.y] == false) {
			if (grid[cur.x][cur.y] == mark || (blind == true && grid[cur.x][cur.y] + mark == RED + GREEN)) {
				visit[cur.x][cur.y] = true;
				wrap(cur.x, cur.y, mark, blind);
			}
		}
	}
	return;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", grid[i]);
	}

	int retval = 0;
	init();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (visit[i][j] == false) {
				visit[i][j] = true;
				++retval;
				wrap(i, j, grid[i][j], false);
			}
		}
	}
	printf("%d ", retval);

	retval = 0;
	init();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (visit[i][j] == false) {
				visit[i][j] = true;
				++retval;
				wrap(i, j, grid[i][j], true);
			}
		}
	}
	printf("%d", retval);

	return 0;
}