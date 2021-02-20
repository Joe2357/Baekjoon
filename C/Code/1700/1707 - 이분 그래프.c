#include <stdio.h>
#include <stdlib.h>

typedef char boolean;
#define True 1
#define False 0
typedef char check;
#define Unvisited 0
#define First 1
#define Second 2

typedef struct Node {
	int index;
	struct Node* next;
} ND;
typedef struct QueueNode {
	int index;
	check group;
} QN;

#define M_L 20001
ND* matrix[M_L];
QN queue[M_L];

ND* createNewNode(int x) {
	ND* newNode = (ND*)malloc(sizeof(ND));
	newNode->index = x;
	newNode->next = NULL;
	return newNode;
}

void insertNewNode(int a, int b) {
	ND* newNode = createNewNode(b);
	newNode->next = matrix[a];
	matrix[a] = newNode;

	newNode = createNewNode(a);
	newNode->next = matrix[b];
	matrix[b] = newNode;
	return;
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int v, e;
		scanf("%d %d", &v, &e);

		for (int i = 1; i <= v; ++i) {
			matrix[i] = NULL;
		}
		while (e--) {
			int a, b;
			scanf("%d %d", &a, &b);
			insertNewNode(a, b);
		}

		check visited[M_L + 1] = { Unvisited };
		boolean result = True;

		for (int i = 1; result && i <= v; ++i) {
			if (visited[i]) {
				continue;
			}

			int front = 0, rear = 1;
			visited[i] = First;
			queue[0] = (QN) { i, First };

			while (result && front != rear) {
				QN node = queue[front++];
				ND* cur = matrix[node.index];
				while (cur != NULL) {
					if (visited[cur->index] == Unvisited) {
						visited[cur->index] = (3 - node.group);
						queue[rear++] = (QN) { cur->index, visited[cur->index] };
					}
					else if (visited[cur->index] + node.group != 3) {
						result = False;
						break;
					}
					cur = cur->next;
				}
			}
		}

		if (result) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}

	return 0;
}