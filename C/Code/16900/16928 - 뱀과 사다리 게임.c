#include <stdio.h>

typedef struct Node {
	int cur;
	int used;
} ND;
typedef char boolean;
#define True 1
#define False 0

#define MAX_IDX 100
#define DICE 6

boolean visited[MAX_IDX + 1];
const int start = 1;
const int end = 100;

int ladder[MAX_IDX + 1];
int snake[MAX_IDX + 1];
ND queue[MAX_IDX + 1];
int result;

int main() {
	int a, b;
	scanf("%d %d", &a, &b);

	while (a--) {
		int c, d;
		scanf("%d %d", &c, &d);
		ladder[c] = d;
	}
	while (b--) {
		int c, d;
		scanf("%d %d", &c, &d);
		snake[c] = d;
	}

	visited[start] = True;
	queue[0] = (ND) { start, 0 };
	int front = 0, rear = 1;

	while (front < rear) {
		ND node = queue[front++];

		if (node.cur == end) {
			printf("%d", node.used);
			break;
		}

		for (int i = DICE; i > 0; --i) {
			if (node.cur + i > end) {
				continue;
			}
			else {
				int dest = node.cur + i;
				if (ladder[dest]) {
					dest = ladder[dest];
				}
				else if (snake[dest]) {
					dest = snake[dest];
				}
				if (visited[dest]) {
					continue;
				}

				visited[dest] = True;
				queue[rear++] = (ND) { dest, node.used + 1 };
			}
		}
	}
	return 0;
}