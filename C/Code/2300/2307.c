#include <stdio.h>
#include <stdlib.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 1000
const int INF = 987654321;
const int START = 1;

typedef struct {
	int distance;
	int node;
} Element;
typedef struct {
	int x, y;
} Link;

typedef struct LinkedListNode {
	int dst;
	int w;
	struct LinkedListNode* next;
} LinkedListNode;

typedef struct Heap {
	Element element[MAX_IDX * 5 + 1];
	int size;
} Heap;

LinkedListNode* grid[MAX_IDX + 1];
int dist[MAX_IDX + 1];
int parent[MAX_IDX + 1];
int n;
Heap heap;
Link path[MAX_IDX + 1];
int path_len;

Link blocked_link;
bool isBlockedLink(int x, int y) {
	return (blocked_link.x == x && blocked_link.y == y) ||
		   (blocked_link.x == y && blocked_link.y == x);
}

void push(Element item) {
	int i = ++(heap.size);
	while (i != 1 && item.distance < heap.element[i / 2].distance) {
		heap.element[i] = heap.element[i / 2];
		i /= 2;
	}
	heap.element[i] = item;
	return;
}

Element pop() {
	int parent, child;
	Element item, temp;

	item = heap.element[1];
	temp = heap.element[(heap.size)--];
	parent = 1;
	child = 2;

	while (child <= heap.size) {
		if (child < heap.size && heap.element[child].distance > heap.element[child + 1].distance)
			child++;
		if (temp.distance <= heap.element[child].distance)
			break;
		heap.element[parent] = heap.element[child];
		parent = child;
		child *= 2;
	}
	heap.element[parent] = temp;
	return item;
}

void insertNewNode(int s, int d, int t) {
	LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
	newNode->dst = d, newNode->w = t;
	newNode->next = grid[s], grid[s] = newNode;
	return;
}

void read_input() {
	int m;
	if (scanf("%d %d", &n, &m) != 2)
		return;
	while (m--) {
		int a, b, t;
		scanf("%d %d %d", &a, &b, &t);
		insertNewNode(a, b, t), insertNewNode(b, a, t);
	}
	return;
}

int dijkstra() {
	for (int i = 1; i <= n; ++i) {
		dist[i] = INF;
	}
	dist[START] = 0;

	Element startNode = {0, START};
	push(startNode);

	while (heap.size > 0) {
		Element current = pop();
		int d = current.distance;
		int now = current.node;

		if (dist[now] < d) { // 이미 처리됨
			continue;
		}

		for (LinkedListNode* curr = grid[now]; curr != NULL; curr = curr->next) {
			if (isBlockedLink(now, curr->dst) == true) { // 검문 중인 간선인 경우
				continue;
			}

			int cost = d + curr->w;
			if (cost < dist[curr->dst]) {
				dist[curr->dst] = cost;
				parent[curr->dst] = now;
				Element nextNode = {cost, curr->dst};
				push(nextNode);
			}
		}
	}

	return dist[n];
}

#define max(a, b) (((a) > (b)) ? (a) : (b))

int main() {
	read_input();
	int best_time = dijkstra();
	blocked_link = (Link){-1, -1};

	if (best_time == INF) { // 애초에 도달할 수 없음
		printf("-1");
		return 0;
	}

	// 간선 하나를 제거 후 다익스트라 재실행
	path_len = 0;
	for (int current_idx = n; current_idx != START; current_idx = parent[current_idx]) {
		path[path_len++] = (Link){current_idx, parent[current_idx]};
	}

	int second_time = best_time;
	for (int i = 0; i < path_len; ++i) {
		blocked_link = path[i];
		second_time = max(second_time, dijkstra());
	}
	printf("%d", (second_time == INF) ? -1 : (second_time - best_time));
	return 0;
}