#include <stdio.h>
#include <stdlib.h>

typedef char boolean;
#define True 1
#define False 0

typedef struct Node {
	int dest;
	struct Node* next;
} ND;

#define MAX_INDEX (int)1e5

int parent[MAX_INDEX];
int queue[MAX_INDEX] = { 0 }, front = -1, rear = 0;
ND* path[MAX_INDEX];

void insertNode(int x, int y) {
	ND* newNode = (ND*)malloc(sizeof(ND));
	newNode->dest = y, newNode->next = path[x];
	path[x] = newNode;
	return;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		parent[i] = -1;
		int a, b;
		scanf("%d %d", &a, &b);
		--a, --b;
		insertNode(a, b), insertNode(b, a);
	}

	while (front < rear) {
		int x = queue[++front];
		ND* point = path[x];
		while (point != NULL) {
			if (parent[point->dest] == -1) {
				parent[point->dest] = x;
				queue[++rear] = point->dest;
			}
			point = point->next;
		}
	}

	for (int i = 1; i < n; ++i) {
		printf("%d\n", parent[i] + 1);
	}
	return 0;
}