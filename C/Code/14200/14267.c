#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int subordinate;
	struct Node* next;
} Node;

#define MAX_IDX (int)(1e5)
const int NONE = -1;
const int ROOT = 1;

Node* company_ranktree[MAX_IDX + 1];
int score[MAX_IDX + 1];
int n, m;

int queue[MAX_IDX + 1];
int front = 0, rear = 0;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		if (x != NONE) {
			Node* newNode = (Node*)malloc(sizeof(Node));
			newNode->subordinate = i;
			newNode->next = company_ranktree[x];
			company_ranktree[x] = newNode;
		}
	}

	while (m--) {
		int i, w;
		scanf("%d %d", &i, &w);
		score[i] += w;
	}

	front = rear = 0;
	queue[rear++] = ROOT;
	while (front < rear) {
		int curr = queue[front++];

		for (Node* currNode = company_ranktree[curr]; currNode != NULL; currNode = currNode->next) {
			score[currNode->subordinate] += score[curr];
			queue[rear++] = currNode->subordinate;
		}
	}

	for (int i = 1; i <= n; i++) {
		printf("%d ", score[i]);
	}
	return 0;
}