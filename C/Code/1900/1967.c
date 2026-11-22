#include <stdio.h>
#include <stdlib.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef struct Node {
	int dest;
	int weight;
	struct Node* next;
} ND;

#define MAX_IDX (10000 + 1)
const int FIRST_ROOT = 1;

int n;
ND* grid[MAX_IDX];

int dist_from_root[MAX_IDX + 1];
int queue[MAX_IDX + 1];
bool visit[MAX_IDX + 2];
int front, rear;

#define max(a, b) (((a) > (b)) ? (a) : (b))

void init() {
	for (int i = FIRST_ROOT; i <= n; ++i) {
		dist_from_root[i] = 0;
		visit[i] = false;
	}
	front = rear = 0;
	return;
}

ND* createNewNode(int d, int w) {
	ND* newNode = (ND*)malloc(sizeof(ND));
	newNode->dest = d, newNode->weight = w, newNode->next = NULL;
	return newNode;
}
void link_node(int s, int d, int w) {
	ND* newNode = createNewNode(d, w);
	newNode->next = grid[s];
	grid[s] = newNode;
	return;
}

int solve(int root) {
	queue[rear++] = root;
	visit[root] = true;

	while (front < rear) {
		int x = queue[front++];
		ND* node = grid[x];

		while (node != NULL) {
			if (visit[node->dest] == false) {
				visit[node->dest] = true;
				dist_from_root[node->dest] = dist_from_root[x] + node->weight;
				queue[rear++] = node->dest;
			}
			node = node->next;
		}
	}

	int retval = 0;
	for (int i = 1; i <= n; ++i) {
		// printf("dist from root %d = %d\n", i, dist_from_root[i]);
		retval = max(retval, dist_from_root[i]);
	}
	return retval;
}

int main() {
	scanf("%d", &n);
	init();
	for (int i = 1; i < n; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		link_node(a, b, c);
		link_node(b, a, c);
	}

	solve(FIRST_ROOT);
	int temp_root = FIRST_ROOT;
	for (int i = 1; i <= n; ++i) {
		if (dist_from_root[temp_root] < dist_from_root[i]) {
			temp_root = i;
		}
	}

	init();
	printf("%d", solve(temp_root));
	return 0;
}