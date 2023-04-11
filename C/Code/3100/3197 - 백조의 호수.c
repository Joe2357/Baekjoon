#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef struct Node {
	int x, y;
} ND;

#define MAX_IDX 1500
char grid[MAX_IDX][MAX_IDX + 1];
int parent[MAX_IDX * MAX_IDX + 1];
int r, c;

#define WALL 'X'
#define VISITED 'V'
#define BLANK '.'
#define BIRD 'L'

#define MAX_DIR 4
ND dir[MAX_DIR] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

ND bird[2];
bool firstBirdAppeared = false;

ND queue[MAX_IDX * MAX_IDX + 1];
int front, rear, endLine;

const int FIRST = 0;
const int SECOND = 1;

bool isValidPosition(ND a) { return (0 <= a.x && a.x < r && 0 <= a.y && a.y < c); }
int IP(ND a) { return a.x * c + a.y; }

int find(int x) {
	if (x == parent[x]) {
		return x;
	} else {
		return parent[x] = find(parent[x]);
	}
}
void merge(int a, int b) {
	int x = find(a), y = find(b);
	if (x != y) {
		parent[y] = parent[b] = x;
	}
	return;
}

void melt() {
	while (front < endLine) {
		ND cur = queue[front++];
		grid[cur.x][cur.y] = BLANK;

		for (int i = 0; i < MAX_DIR; ++i) {
			ND next = (ND){cur.x + dir[i].x, cur.y + dir[i].y};
			if (isValidPosition(next)) {
				switch (grid[next.x][next.y]) {
					case BLANK: {
						merge(IP(next), IP(cur));
						break;
					}
					case WALL: {
						if (grid[next.x][next.y] == WALL) {
							grid[next.x][next.y] = VISITED;
							queue[rear++] = next;
							break;
						}
					}
				}
			}
		}
	}
	return;
}

int main() {
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; ++i) {
		scanf("%s", grid[i]);
		for (int j = 0; j < c; ++j) {
			parent[IP((ND){i, j})] = IP((ND){i, j});
		}
	}

	// blank group init
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			switch (grid[i][j]) {
				case BIRD: {
					bird[firstBirdAppeared++] = (ND){i, j};
					grid[i][j] = BLANK;
				}
				case BLANK: {
					queue[rear++] = (ND){i, j};
					break;
				}
				case WALL: {
					break;
				}
			}
		}
	}

	endLine = rear;
	while (front < endLine) {
		ND cur = queue[front++];

		for (int i = 0; i < MAX_DIR; ++i) {
			ND next = (ND){cur.x + dir[i].x, cur.y + dir[i].y};
			if (isValidPosition(next)) {
				if (grid[next.x][next.y] == WALL) {
					grid[next.x][next.y] = VISITED;
					queue[rear++] = next;
				} else if (grid[next.x][next.y] == BLANK) {
					merge(IP(cur), IP(next));
				}
			}
		}
	}

	for (int i = 0; i <= r * c; ++i) {
		if (find(IP(bird[FIRST])) == find(IP(bird[SECOND]))) {
			printf("%d", i);
			break;
		}

		endLine = rear;
		melt();
	}

	return 0;
}