#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef struct Position {
	int x, y;
} Position;

#define CHESS_SIZE 6

Position path[CHESS_SIZE * CHESS_SIZE];
bool visit[CHESS_SIZE][CHESS_SIZE];

#define abs(x) ((x) < 0 ? -(x) : (x))

void read_input() {
	for (int i = 0; i < CHESS_SIZE * CHESS_SIZE; ++i) {
		char c;
		int d;
		scanf("%c%d\n", &c, &d);

		path[i] = (Position){c - 'A', d - 1};
	}
	return;
}

bool isKnightMove(Position a, Position b) {
	int dx = abs(a.x - b.x);
	int dy = abs(a.y - b.y);

	return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
}

bool isValidPath() {
	visit[path[0].x][path[0].y] = true;
	for (int i = 1; i < CHESS_SIZE * CHESS_SIZE; ++i) {
		if (isKnightMove(path[i - 1], path[i]) == false || visit[path[i].x][path[i].y] == true) {
			return false;
		} else {
			visit[path[i].x][path[i].y] = true;
		}
	}

	if (isKnightMove(path[CHESS_SIZE * CHESS_SIZE - 1], path[0]) == false) {
		return false;
	} else {
		return true;
	}
}

int main() {
	read_input();
	printf("%s", (isValidPath() == true) ? "Valid" : "Invalid");
	return 0;
}