#include <stdio.h>
#include <stdlib.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef struct LinkedListNode {
	int data;
	struct LinkedListNode* next;
} LinkedListNode;
typedef struct Queuenode {
	int num, dist;
} Queuenode;

#define MAX_IDX 20000
const int START = 1;

LinkedListNode* grid[MAX_IDX + 1];
int n, m;

bool visit[MAX_IDX + 1 + 1];
Queuenode queue[MAX_IDX + 1];
int front = 0, rear = 0;

#define min(a, b) ((a) < (b) ? (a) : (b))

void read_input() {
	scanf("%d %d", &n, &m);

	while (m--) {
		int u, v;
		scanf("%d %d", &u, &v);
		LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
		newNode->data = v;
		newNode->next = grid[u];
		grid[u] = newNode;

		newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
		newNode->data = u;
		newNode->next = grid[v];
		grid[v] = newNode;
	}
	return;
}

void solve() {
	visit[START] = true;
	queue[rear++] = (Queuenode){START, 0};

	int result_num = 0, result_dist = 0, result_cnt = 0;
	while (front < rear) {
		Queuenode curr = queue[front++];
		if (curr.dist > result_dist) {
			result_dist = curr.dist;
			result_num = curr.num;
			result_cnt = 1;
		} else if (curr.dist == result_dist) {
			result_cnt += 1;
			result_num = min(result_num, curr.num);
		}

		for (LinkedListNode* adj = grid[curr.num]; adj != NULL; adj = adj->next) {
			if (visit[adj->data] == false) {
				visit[adj->data] = true;
				queue[rear++] = (Queuenode){adj->data, curr.dist + 1};
			}
		}
	}

	printf("%d %d %d", result_num, result_dist, result_cnt);
	return;
}

int main() {
	read_input();
	solve();
	return 0;
}