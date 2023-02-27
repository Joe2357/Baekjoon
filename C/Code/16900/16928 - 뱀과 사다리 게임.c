#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef struct Path {
	int x, y;
} PT;
typedef struct Node {
	int x, c;
} ND;

#define MAX_IDX (100 + 1)
#define START 1
#define END 100
#define DICE 6

bool visit[MAX_IDX];
PT path[30];
int pathLen;
ND q[MAX_IDX];
int front, rear;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	pathLen = n + m;
	for (int i = 0; i < pathLen; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		path[i] = (PT){a, b};
	}

	visit[START] = true;
	q[rear++] = (ND){START, 0};
	while (front < rear) {
		ND cur = q[front++];
		if (cur.x == END) {
			printf("%d", cur.c);
			break;
		}

		for (int i = 1; i <= DICE; ++i) {
			int next = cur.x + i;
			for (int j = 0; j < pathLen; ++j) {
				if (next == path[j].x) {
					next = path[j].y;
				}
			}
			if (next <= END && visit[next] == false) {
				visit[next] = true;
				q[rear++] = (ND){next, cur.c + 1};
			}
		}
	}

	return 0;
}