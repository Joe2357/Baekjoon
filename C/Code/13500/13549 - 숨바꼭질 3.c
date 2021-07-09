#include <stdio.h>

typedef char boolean;
#define True 1
#define False 0

#define MAX_IDX (int)(2e5 + 1)
#define INF (int)1e5

typedef struct Node {
	int c, m;
} ND;

boolean visited[MAX_IDX];
int n, k;

int main() {
	scanf("%d %d", &n, &k);

	ND queue[MAX_IDX];
	queue[0] = (ND){n, 0};
	visited[n] = True;
	int front = 0, rear = 1;

	while (front < rear) {
		ND node = queue[front++];
		// printf("a : %d | %d\n", node.m, node.c);
		int x = node.c;
		if (x < 0) {
			continue;
		}
		while (x < MAX_IDX) {
			if (x == k) {
				printf("%d", node.m);
				return 0;
			}

			if (x + 1 < MAX_IDX && !visited[x + 1]) {
				visited[x + 1] = True;
				queue[rear++] = (ND){x + 1, node.m + 1};
			}
			if (x > 0 && !visited[x - 1]) {
				visited[x - 1] = True;
				queue[rear++] = (ND){x - 1, node.m + 1};
			}

			if (x == 0) {
				break;
			}
			if ((x <<= 1) < MAX_IDX) {
				visited[x] = True;
			}
		}
	}
	return 0;
}