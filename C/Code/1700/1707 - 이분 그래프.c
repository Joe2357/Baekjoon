#include <stdio.h>
#include <stdlib.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef struct Pair {
	int first, second;
} pair;
typedef struct QueueNode {
	int idx, g;
} QN;
typedef struct Node {
	int x;
	struct Node* next;
} ND;

#define MAX_IDX (20000 + 1)
#define MAX_EDGE 200000

const int EMPTY = 0;
const int FIRST = 1;
const int SECOND = 2;

ND* adjacency_list[MAX_IDX + 1];
int v, e;

int group[MAX_IDX + 1];

ND* createNewNode(int x) {
	ND* node = (ND*)malloc(sizeof(ND));
	node->x = x;
	node->next = NULL;
	return node;
}
void free_all() {
	for (int i = 1; i <= v; ++i) {
		ND* cur = adjacency_list[i];

		while (cur != NULL) {
			adjacency_list[i] = cur->next;
			free(cur);
			cur = adjacency_list[i];
		}
	}
	return;
}

void init() {
	for (int i = 1; i <= v; ++i) {
		adjacency_list[i] = NULL;
		group[i] = EMPTY;
	}
	return;
}
void read_input() {
	scanf("%d %d", &v, &e);
	while (e--) {
		int a, b;
		scanf("%d %d", &a, &b);

		ND* newNode = createNewNode(b);
		newNode->next = adjacency_list[a];
		adjacency_list[a] = newNode;

		newNode = createNewNode(a);
		newNode->next = adjacency_list[b];
		adjacency_list[b] = newNode;
	}
	return;
}

bool bfs(int x) {
	QN q[MAX_IDX + 1];
	int front = 0, rear = 0;

	q[rear++] = (QN){x, group[x]};

	while (front < rear) {
		QN cur = q[front++];

		ND* point = adjacency_list[cur.idx];
		while (point != NULL) {
			int target = point->x;

			if (group[target] == group[cur.idx]) {
				return false;
			} else if (group[target] == EMPTY) {
				group[target] = (FIRST + SECOND) - group[cur.idx];
				q[rear++] = (QN){target, group[target]};
			}

			point = point->next;
		}
	}
	return true;
}
bool solve() {
	for (int i = 1; i <= v; ++i) {
		if (group[i] == EMPTY) {
			group[i] = FIRST;

			if (bfs(i) == false) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	int k;
	scanf("%d", &k);

	while (k--) {
		init();
		read_input();
		printf("%s\n", solve() ? "YES" : "NO");
		free_all();
	}

	return 0;
}