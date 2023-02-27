#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef struct Node {
	int x, y;
} ND;
typedef struct QueueNode {
	ND red, blue;
	int time;
} QN;

#define MAX_IDX 10
char grid[MAX_IDX][MAX_IDX + 1];
int n, m;
ND hole;
bool isAnswerExists = false;

#define MAX_LEN 3000000
QN q[MAX_LEN];
int front = 0, rear = 0;

#define MAX_DIR 4
ND dir[4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

#define WALL '#'
#define BLANK '.'
#define RED 'R'
#define BLUE 'B'
#define GOAL -1

int main() {
	ND red, blue;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%s", grid[i]);
		for (int j = 0; j < m; ++j) {
			switch (grid[i][j]) {
				case 'R': {
					red = (ND){i, j};
					grid[i][j] = BLANK;
					break;
				}
				case 'B': {
					blue = (ND){i, j};
					grid[i][j] = BLANK;
					break;
				}
				case 'O': {
					hole = (ND){i, j};
					break;
				}
			}
		}
	}

	q[rear++] = (QN){red, blue, 0};

#define MAX_TIME 10
	while (isAnswerExists == false && front < rear) {
		QN cur = q[front++];
		if (cur.time == MAX_TIME) {
			break;
		}

		for (int i = 0; i < MAX_DIR; ++i) {
			ND rCur = cur.red, bCur = cur.blue;
			grid[rCur.x][rCur.y] = RED;
			grid[bCur.x][bCur.y] = BLUE;

			bool isRedGoal = false, isBlueGoal = false;

			// red 1
			while (grid[rCur.x + dir[i].x][rCur.y + dir[i].y] == BLANK) {
				grid[rCur.x][rCur.y] = BLANK;
				rCur.x += dir[i].x, rCur.y += dir[i].y;
				grid[rCur.x][rCur.y] = RED;
			}
			if (rCur.x + dir[i].x == hole.x && rCur.y + dir[i].y == hole.y) {
				grid[rCur.x][rCur.y] = BLANK;
				rCur = hole;
				isRedGoal = true;
			}

			// blue 1
			while (grid[bCur.x + dir[i].x][bCur.y + dir[i].y] == BLANK) {
				grid[bCur.x][bCur.y] = BLANK;
				bCur.x += dir[i].x, bCur.y += dir[i].y;
				grid[bCur.x][bCur.y] = BLUE;
			}
			if (bCur.x + dir[i].x == hole.x && bCur.y + dir[i].y == hole.y) {
				grid[bCur.x][bCur.y] = BLANK;
				bCur = hole;
				isBlueGoal = true;
			}

			if (isBlueGoal == true) {
				if (isRedGoal == false) {
					grid[rCur.x][rCur.y] = BLANK;
				}
				continue;
			}
			if (isRedGoal == true) {
				isAnswerExists = true;
				printf("%d", cur.time + 1);
				break;
			}

			// red 2
			while (grid[rCur.x + dir[i].x][rCur.y + dir[i].y] == BLANK) {
				grid[rCur.x][rCur.y] = BLANK;
				rCur.x += dir[i].x, rCur.y += dir[i].y;
				grid[rCur.x][rCur.y] = RED;
			}
			if (rCur.x + dir[i].x == hole.x && rCur.y + dir[i].y == hole.y) {
				grid[rCur.x][rCur.y] = BLANK;
				rCur = hole;
				isRedGoal = true;
			}
			if (isRedGoal == true) {
				isAnswerExists = true;
				printf("%d", cur.time + 1);
				break;
			}

			// reset phase
			q[rear++] = (QN){rCur, bCur, cur.time + 1};
			grid[rCur.x][rCur.y] = BLANK;
			grid[bCur.x][bCur.y] = BLANK;
		}
	}

	if (isAnswerExists == false) {
		printf("-1");
	}
	return 0;
}