#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;
typedef struct Node {
	int x, y;
} ND;

#define MAX_IDX 100
char grid[MAX_IDX][MAX_IDX + 1];
bool visit[MAX_IDX][MAX_IDX];
int h, w;
int document;

#define ALPHABET 26
bool key[ALPHABET];
char keyInput[ALPHABET + 1];

#define DIR 4
ND dir[DIR] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

#define QUEUE_LEN (MAX_IDX * MAX_IDX + 1)
ND queue[QUEUE_LEN];
ND door[ALPHABET][QUEUE_LEN];
int doorLen[ALPHABET];
int front, rear;

#define bigAlphabetIndex(x) ((x) - ('A'))
#define smallAlphabetIndex(x) ((x) - ('a'))

void init() {
	front = rear = 0;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			visit[i][j] = false;
		}
	}
	for (int i = 0; i < ALPHABET; ++i) {
		key[i] = false;
		doorLen[i] = 0;
	}
	document = 0;
	return;
}

bool isValidPosition(ND c) {
	return ((0 <= c.x && c.x < h) && (0 <= c.y && c.y < w));
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		init();
		scanf("%d %d", &h, &w);
		for (int i = 0; i < h; ++i) {
			scanf("%s", grid[i]);
		}
		scanf("%s", keyInput);
		for (int i = 0; keyInput[i] > '0'; ++i) {
			key[smallAlphabetIndex(keyInput[i])] = true;
		}
		for (int i = 0; i < w; ++i) {
			if (grid[0][i] != '*') {
				visit[0][i] = true;
				queue[rear++] = (ND){0, i};
			}
			if (grid[h - 1][i] != '*') {
				visit[h - 1][i] = true;
				queue[rear++] = (ND){h - 1, i};
			}
		}
		for (int i = 1; i < h - 1; ++i) {
			if (grid[i][0] != '*') {
				visit[i][0] = true;
				queue[rear++] = (ND){i, 0};
			}
			if (grid[i][w - 1] != '*') {
				visit[i][w - 1] = true;
				queue[rear++] = (ND){i, w - 1};
			}
		}

		// bfs
		while (front < rear) {
			ND cur = queue[front++];
			char curChar = grid[cur.x][cur.y];

			if (curChar == '$') {
				++document;
			}
			if ('a' <= curChar && curChar <= 'z') {
				if (key[smallAlphabetIndex(curChar)] == false) {
					key[smallAlphabetIndex(curChar)] = true;
					for (int i = 0; i < doorLen[smallAlphabetIndex(curChar)]; ++i) {
						queue[rear++] = door[smallAlphabetIndex(curChar)][i];
					}
				}
			}
			if ('A' <= curChar && curChar <= 'Z') {
				if (key[bigAlphabetIndex(curChar)] == false) {
					visit[cur.x][cur.y] = true;
					door[bigAlphabetIndex(curChar)][doorLen[bigAlphabetIndex(curChar)]++] = cur;
					continue;
				}
			}

			for (int i = 0; i < DIR; ++i) {
				ND next = (ND){cur.x + dir[i].x, cur.y + dir[i].y};
				if (isValidPosition(next) && grid[next.x][next.y] != '*' && visit[next.x][next.y] == false) {
					visit[next.x][next.y] = true;
					queue[rear++] = next;
				}
			}
		}

		printf("%d\n", document);
	}
	return 0;
}