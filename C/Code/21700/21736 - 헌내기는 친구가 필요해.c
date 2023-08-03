#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef struct Node {
	int x, y;
} ND;

const char EMPTY = 'O';
const char WALL = 'X';
const char DOYEON = 'I';
const char PERSON = 'P';

#define MAX_IDX 600
char grid[MAX_IDX][MAX_IDX + 1];
bool visit[MAX_IDX][MAX_IDX + 1];
int n, m;

ND q[MAX_IDX * MAX_IDX];
int front, rear;

#define MAX_DIR 4
ND dir[MAX_DIR] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%s", grid + i);
		for (int j = 0; j < m; ++j) {
			if (grid[i][j] == DOYEON) {
				q[rear++] = (ND){i, j};
			}
		}
	}

	int retval = 0;
	while (front < rear) {
		ND cur = q[front++];
		if (grid[cur.x][cur.y] == PERSON) {
			++retval;
		}

		for (int i = 0; i < MAX_DIR; ++i) {
			ND new = (ND){cur.x + dir[i].x, cur.y + dir[i].y};
			if (0 <= new.x&& new.x < n && 0 <= new.y&& new.y < m) {
				if (grid[new.x][new.y] != WALL && visit[new.x][new.y] == false) {
					visit[new.x][new.y] = true;
					q[rear++] = new;
				}
			}
		}
	}

	if (retval == 0) {
		printf("TT");
	} else {
		printf("%d", retval);
	}
	return 0;
}