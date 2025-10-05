#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef struct Position {
	int x, y;
} PS;

#define MAX_DIR 8
#define MAX_IDX 8
#define BLACK 'B'
#define WHITE 'W'
#define EMPTY '.'

PS dir[MAX_DIR] = {
	{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

char grid[MAX_IDX][MAX_IDX + 1];

#define max(a, b) (((a) > (b)) ? (a) : (b))

void read_input() {
	for (int i = 0; i < MAX_IDX; ++i) {
		scanf("%s", grid[i]);
	}
	return;
}

bool isValidPosition(PS cur) {
	return (0 <= cur.x && cur.x < MAX_IDX && 0 <= cur.y && cur.y < MAX_IDX);
}

int solve(PS cur) {
	if (grid[cur.x][cur.y] != EMPTY) {
		return 0;
	}

	int ret = 0;
	for (int i = 0; i < MAX_DIR; ++i) {
		int temp = 0;
		bool exitCode = false;
		for (PS newPosition = (PS){cur.x + dir[i].x, cur.y + dir[i].y};
			 exitCode == false && isValidPosition(newPosition) == true;
			 newPosition.x += dir[i].x, newPosition.y += dir[i].y) {
			switch (grid[newPosition.x][newPosition.y]) {
				case WHITE: {
					temp += 1;
					break;
				}
				case BLACK: {
					ret += temp;
					exitCode = true;
					break;
				}
				case EMPTY: {
					exitCode = true;
					break;
				}
			}
		}
	}

	return ret;
}

int main() {
	read_input();

	int ret = 0;
	for (int i = 0; i < MAX_IDX; ++i) {
		for (int j = 0; j < MAX_IDX; ++j) {
			ret = max(ret, solve((PS){i, j}));
		}
	}
	printf("%d", ret);
	return 0;
}