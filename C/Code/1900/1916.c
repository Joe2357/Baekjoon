#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

const int INF = 987654321;
#define MAX_IDX 1000

int grid[MAX_IDX + 1][MAX_IDX + 1 + 1];
int n, m;
int start_point, end_point;

int distance[MAX_IDX + 1];
bool visit[MAX_IDX + 1 + 1];

#define min(a, b) ((a) < (b) ? (a) : (b))

void init() {
	for (int i = 1; i <= MAX_IDX; i++) {
		distance[i] = INF;
		visit[i] = false;
		for (int j = 1; j <= MAX_IDX; j++) {
			grid[i][j] = (i == j) ? 0 : INF;
		}
	}
	return;
}

void read_input() {
	scanf("%d %d", &n, &m);
	while (m--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		grid[a][b] = min(grid[a][b], c);
	}
	scanf("%d %d", &start_point, &end_point);
	return;
}

void dijkstra() {
	distance[start_point] = 0;

	// Step 1. 최소 거리 정점 선택
	for (int i = 1; i <= n; i++) {
		int min_distance = INF;
		int min_idx = -1;
		for (int j = 1; j <= n; j++) {
			if (visit[j] == false && distance[j] < min_distance) {
				min_distance = distance[j];
				min_idx = j;
			}
		}
		if (min_idx == -1) {
			break;
		}
		visit[min_idx] = true;

		// Step 2. 선택된 정점 기준으로 거리 갱신
		for (int j = 1; j <= n; j++) {
			if (visit[j] == false && grid[min_idx][j] != INF) {
				distance[j] = min(distance[j], distance[min_idx] + grid[min_idx][j]);
			}
		}
	}
	return;
}

int main() {
	init();
	read_input();
	dijkstra();
	printf("%d", distance[end_point]);
	return 0;
}