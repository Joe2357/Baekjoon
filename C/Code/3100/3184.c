#include <stdbool.h>
#include <stdio.h>

const char EMPTY = '.';
const char FENCE = '#';
const char SHEEP = 'o';
const char WOLF = 'v';

#define MAX_IDX 250
#define MAX_DIR 4

typedef struct Position {
	int x, y;
} Position;

const Position dir[MAX_DIR] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

char grid[MAX_IDX][MAX_IDX + 1];
int r, c;

bool visit[MAX_IDX][MAX_IDX];
int sheep_cnt, wolf_cnt;

Position q[MAX_IDX * MAX_IDX];
int front, rear;

void read_input() {
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; ++i) {
		scanf("%s", grid[i]);
	}
	return;
}

void bfs(int x, int y) {
	int s = 0, w = 0;
	front = rear = 0;
	q[rear++] = (Position){x, y};

	while (front < rear) {
		Position cur = q[front++];
		s += (grid[cur.x][cur.y] == SHEEP);
		w += (grid[cur.x][cur.y] == WOLF);

		for (int i = 0; i < MAX_DIR; ++i) {
			Position newPos = (Position){cur.x + dir[i].x, cur.y + dir[i].y};
			if (0 <= newPos.x && newPos.x < r && 0 <= newPos.y && newPos.y < c) {
				if (visit[newPos.x][newPos.y] == false && grid[newPos.x][newPos.y] != FENCE) {
					visit[newPos.x][newPos.y] = true;
					q[rear++] = newPos;
				}
			}
		}
	}

	if (s > w) {
		sheep_cnt += s;
	} else {
		wolf_cnt += w;
	}
	return;
}

void solve() {
	for (int x = 0; x < r; ++x) {
		for (int y = 0; y < c; ++y) {
			if (visit[x][y] == false && grid[x][y] != FENCE) {
				visit[x][y] = true;
				bfs(x, y);
			}
		}
	}
	return;
}

int main() {
	read_input();
	solve();
	printf("%d %d", sheep_cnt, wolf_cnt);
	return 0;
}