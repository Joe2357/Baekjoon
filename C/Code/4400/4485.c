#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_IDX 125
const int INF = 987654321;
#define MAX_DIR 4

int grid[MAX_IDX][MAX_IDX];
int dist[MAX_IDX][MAX_IDX];
int n;
int problem_number;

int dr[MAX_DIR] = {-1, 1, 0, 0};
int dc[MAX_DIR] = {0, 0, -1, 1};

typedef struct {
	int r, c, cost;
} Node;

Node heap[MAX_IDX * MAX_IDX * 4];
int heap_size = 0;

void push(Node node) {
	int i = ++heap_size;
	while (i != 1 && node.cost < heap[i / 2].cost) {
		heap[i] = heap[i / 2];
		i /= 2;
	}
	heap[i] = node;
	return;
}

Node pop() {
	Node res = heap[1];
	Node last = heap[heap_size--];
	int parent = 1, child = 2;

	while (child <= heap_size) {
		if (child < heap_size && heap[child].cost > heap[child + 1].cost) {
			child += 1;
		}
		if (last.cost <= heap[child].cost) {
			break;
		}
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = last;
	return res;
}

void read_input() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &grid[i][j]);
			dist[i][j] = INF;
		}
	}
	return;
}

int solve() {
	heap_size = 0; // 힙 초기화

	// 시작점 설정
	dist[0][0] = grid[0][0];
	Node start = {0, 0, dist[0][0]};
	push(start);

	while (heap_size > 0) {
		Node curr = pop();
		int r = curr.r;
		int c = curr.c;
		int cost = curr.cost;

		// 이미 더 짧은 경로를 찾았다면 스킵
		if (dist[r][c] < cost) {
			continue;
		}

		if (r == n - 1 && c == n - 1) {
			return dist[r][c];
		}

		// 다익스트라 알고리즘
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
				int next_cost = cost + grid[nr][nc];
				if (next_cost < dist[nr][nc]) {
					dist[nr][nc] = next_cost;
					Node next = {nr, nc, next_cost};
					push(next);
				}
			}
		}
	}

	return dist[n - 1][n - 1];
}

int main() {
	while (true) {
		scanf("%d", &n);
		if (n == 0) {
			break;
		}

		read_input();
		printf("Problem %d: %d\n", ++problem_number, solve());
	}
	return 0;
}