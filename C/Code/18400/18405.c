#include <stdio.h>
#include <stdlib.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef struct Position {
	int x, y;
} POS;
typedef struct Node {
	POS pos;
	struct Node* next;
} ND;

#define MAX_IDX 200
#define MAX_VIRUS 1000
const int NONE = 0;

int grid[MAX_IDX][MAX_IDX];
ND* virus_list[MAX_VIRUS + 1];
int n, k;
int s, x, y;

POS queue[MAX_IDX * MAX_IDX];
int front, rear;

#define MAX_DIR 4
POS dir[MAX_DIR] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void init() {
	for (int i = 0; i < MAX_IDX; i++) {
		for (int j = 0; j < MAX_IDX; j++) {
			grid[i][j] = NONE;
		}
	}
	return;
}

void insertNewNode(int a, int posX, int posY) {
	ND* newNode = (ND*)malloc(sizeof(ND));
	newNode->pos.x = posX, newNode->pos.y = posY;
	newNode->next = virus_list[a];
	virus_list[a] = newNode;
	return;
}

void read_input() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &grid[i][j]);
			insertNewNode(grid[i][j], i, j);
		}
	}
	scanf("%d %d %d", &s, &x, &y);
	--x, --y;
	return;
}

void queue_init() {
	front = rear = 0;
	for (int i = 1; i <= k; ++i) {
		for (ND* cur = virus_list[i]; cur != NULL; cur = cur->next) {
			queue[rear++] = cur->pos;
		}
	}
	return;
}

void spread() {
	int size = rear - front;
	for (int i = 0; i < size; ++i) {
		POS cur = queue[front++];

		for (int d = 0; d < MAX_DIR; ++d) {
			POS new_pos = (POS){cur.x + dir[d].x, cur.y + dir[d].y};
			if (0 <= new_pos.x && new_pos.x < n && 0 <= new_pos.y && new_pos.y < n) {
				if (grid[new_pos.x][new_pos.y] == NONE) {
					grid[new_pos.x][new_pos.y] = grid[cur.x][cur.y];
					queue[rear++] = new_pos;
				} else {
					continue;
				}
			} else {
				continue;
			}
		}
	}
	return;
}

int main() {
	init();
	read_input();
	queue_init();

	for (int i = 0; i < s && grid[x][y] == NONE; ++i) {
		spread();
	}

	printf("%d\n", grid[x][y]);
	return 0;
}