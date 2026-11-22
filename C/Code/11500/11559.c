#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_ROW 12
#define MAX_COL 6
#define MAX_DIR 4
const int BOOM_LOW_BOUND = 4;
const char EMPTY = '.', RED = 'R', GREEN = 'G', BLUE = 'B', PURPLE = 'P', YELLOW = 'Y';

typedef struct Position {
	int x, y;
} Position;
Position dir[MAX_DIR] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

char grid[MAX_ROW][MAX_COL + 1];
bool visit[MAX_ROW][MAX_COL + 1];

void read_input() {
	for (int i = 0; i < MAX_ROW; ++i) {
		scanf("%s", grid[i]);
	}
	return;
}

void visit_init() {
	for (int i = 0; i < MAX_ROW; ++i) {
		for (int j = 0; j < MAX_COL; ++j) {
			visit[i][j] = false;
		}
	}
	return;
}

bool bfs(int x, int y) {
	Position queue[MAX_ROW * MAX_COL + 1] = {(Position){x, y}};
	visit[x][y] = true;
	int front = 0, rear = 1;

	while (front < rear) {
		Position cur = queue[front++];

		for (int i = 0; i < MAX_DIR; ++i) {
			Position new = (Position){cur.x + dir[i].x, cur.y + dir[i].y};
			if (new.x >= 0 && new.x < MAX_ROW && new.y >= 0 && new.y < MAX_COL) {
				if (visit[new.x][new.y] == false && grid[new.x][new.y] == grid[queue[0].x][queue[0].y]) {
					visit[new.x][new.y] = true;
					queue[rear++] = new;
				}
			}
		}
	}

	if (rear >= BOOM_LOW_BOUND) {
		for (int i = 0; i < rear; ++i) {
			Position cur = queue[i];
			grid[cur.x][cur.y] = EMPTY;
		}
		return true;
	} else {
		return false;
	}
}

bool step() {
	bool isBoom = false;
	visit_init();

	// 터뜨리기
	for (int i = 0; i < MAX_ROW; ++i) {
		for (int j = 0; j < MAX_COL; ++j) {
			if (grid[i][j] != EMPTY && visit[i][j] == false) {
				isBoom |= bfs(i, j);
			}
		}
	}
	if (isBoom == false) {
		return false;
	}

	// 내리기
	for (int j = 0; j < MAX_COL; ++j) {
		int cur_row = MAX_ROW - 1;
		for (int i = MAX_ROW - 1; i >= 0; --i) {
			if (grid[i][j] != EMPTY) {
				grid[cur_row--][j] = grid[i][j];
			}
		}
		for (int i = cur_row; i >= 0; --i) {
			grid[i][j] = EMPTY;
		}
	}

	return true;
}

void print_grid() {
	for (int i = 0; i < MAX_ROW; ++i) {
		printf("%s\n", grid[i]);
	}
	printf("\n");
	return;
}

int main() {
	read_input();
	// print_grid();

	int ret = 0;
	while (true) {
		if (step() == true) {
			// print_grid();
			ret += 1;
		} else {
			break;
		}
	}

	printf("%d", ret);
	return 0;
}