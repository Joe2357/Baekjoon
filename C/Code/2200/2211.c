#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_IDX 1000
const int INF = 987654321;
const int SUPER_COMPUTER = 1;

typedef struct Edge {
	int a, b, c;
} Edge;
typedef struct HeapNode {
	int idx_point, dist;
	Edge used_edge;
} HeapNode;
typedef struct GridNode {
	int idx_point, edge_weight;
	struct GridNode* next;
} GridNode;

int distance[MAX_IDX + 1];
int n, m;
GridNode* LinkedListMap[MAX_IDX + 1];
HeapNode heap[MAX_IDX * MAX_IDX];
int heap_size = 0;
Edge answer[MAX_IDX * MAX_IDX];
int answer_size = 0;

void heap_push(HeapNode node) {
	heap[heap_size] = node;
	int idx = heap_size;
	heap_size++;

	while (idx > 0) {
		int parent_idx = (idx - 1) / 2;
		if (heap[parent_idx].dist > heap[idx].dist) {
			HeapNode temp = heap[parent_idx];
			heap[parent_idx] = heap[idx];
			heap[idx] = temp;
			idx = parent_idx;
		} else {
			break;
		}
	}
	return;
}
HeapNode heap_pop() {
	HeapNode result = heap[0];
	heap_size--;
	heap[0] = heap[heap_size];

	int idx = 0;
	while (true) {
		int left_child_idx = idx * 2 + 1;
		int right_child_idx = idx * 2 + 2;
		int smallest_idx = idx;

		if (left_child_idx < heap_size && heap[left_child_idx].dist < heap[smallest_idx].dist) {
			smallest_idx = left_child_idx;
		}
		if (right_child_idx < heap_size && heap[right_child_idx].dist < heap[smallest_idx].dist) {
			smallest_idx = right_child_idx;
		}
		if (smallest_idx != idx) {
			HeapNode temp = heap[idx];
			heap[idx] = heap[smallest_idx];
			heap[smallest_idx] = temp;
			idx = smallest_idx;
		} else {
			break;
		}
	}
	return result;
}
bool isHeapEmpty() {
	return heap_size == 0;
}

GridNode* createGridNode(int idx_point, int edge_weight) {
	GridNode* newNode = (GridNode*)malloc(sizeof(GridNode));
	newNode->idx_point = idx_point;
	newNode->edge_weight = edge_weight;
	newNode->next = NULL;
	return newNode;
}
void insertEdge(int a, int b, int c) {
	GridNode* newNodeA = createGridNode(b, c);
	newNodeA->next = LinkedListMap[a];
	LinkedListMap[a] = newNodeA;
	GridNode* newNodeB = createGridNode(a, c);
	newNodeB->next = LinkedListMap[b];
	LinkedListMap[b] = newNodeB;
	return;
}

void read_input() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		insertEdge(a, b, c);
	}
	return;
}

// 슈퍼컴퓨터로부터의 최단거리는 간선 복구 이후에도 유지되어야 함
// 최단경로 만들 때 사용되는 간선들의 집합만 복구하면 됨
void dijkstra(int start_point) {
	distance[start_point] = 0;
	heap_push((HeapNode){start_point, 0, {0, 0, 0}});

	while (isHeapEmpty() == false) {
		HeapNode cur = heap_pop();
		if (cur.dist > distance[cur.idx_point]) {
			continue;
		}

		answer[answer_size++] = cur.used_edge;

		for (GridNode* curr = LinkedListMap[cur.idx_point]; curr != NULL; curr = curr->next) {
			if (distance[curr->idx_point] > distance[cur.idx_point] + curr->edge_weight) {
				distance[curr->idx_point] = distance[cur.idx_point] + curr->edge_weight;
				heap_push((HeapNode){curr->idx_point, distance[curr->idx_point], {cur.idx_point, curr->idx_point, curr->edge_weight}});
			}
		}
	}
	return;
}

void init() {
	for (int i = 1; i <= n; i++) {
		distance[i] = INF;
	}
	distance[SUPER_COMPUTER] = 0;
	dijkstra(SUPER_COMPUTER);
	return;
}

int main() {
	read_input();
	init();
	printf("%d\n", answer_size - 1);
	for (int i = 1; i < answer_size; ++i) {
		printf("%d %d\n", answer[i].a, answer[i].b);
	}
	return 0;
}