#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int x;
	struct Node* next;
} ND;

#define N 32000

ND* grid[N + 1] = {NULL};
int degree[N + 1];
int queue[N];
int front = 0, rear = 0;

ND* createNewNode(int a) {
	ND* newNode = (ND*)malloc(sizeof(ND));
	newNode->x = a;
	return newNode;
}

void insert(int x, int y) {
	if (grid[x] != NULL) {
		ND* newNode = createNewNode(y);
		newNode->next = grid[x];
		grid[x] = newNode;
	} else {
		grid[x] = createNewNode(y);
	}
	return;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	while (m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		insert(a, b);
		++degree[b];
	}

	for (int i = 1; i <= n; ++i) {
		if (degree[i] == 0) {
			queue[rear++] = i;
		}
	}

	while (front < rear) {
		int a = queue[front++];
		printf("%d ", a);
		ND* head = grid[a];
		while (head) {
			--degree[head->x];
			if (degree[head->x] == 0) {
				queue[rear++] = head->x;
			}
			head = head->next;
		}
	}
	return 0;
}