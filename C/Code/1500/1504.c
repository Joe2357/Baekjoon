#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define INF 987654321
#define MAX_IDX (800 + 1)

int matrix[MAX_IDX][MAX_IDX + 1];
int n, e;
int v1, v2;
int start, end;

int fromV1[MAX_IDX], fromV2[MAX_IDX];

void init() {
	for (int i = 0; i < MAX_IDX; ++i) {
		for (int j = 0; j < MAX_IDX; ++j) {
			matrix[i][j] = INF;
		}
	}
	return;
}

void dijkstra(int* dist, int v) {
	bool visit[MAX_IDX + 1] = {false};

	for (int i = 0; i <= n; ++i) {
		dist[i] = INF;
	}
	dist[v] = 0;

	int current_vertex;
	while (true) {
		current_vertex = 0;
		for (int i = 1; i <= n; ++i) {
			if (visit[i] == false && dist[i] < dist[current_vertex]) {
				current_vertex = i;
			}
		}
		if (current_vertex == 0) {
			break;
		}
		visit[current_vertex] = true;

		for (int i = 1; i <= n; ++i) {
			if (matrix[current_vertex][i] < INF) {
				if (dist[i] > dist[current_vertex] + matrix[current_vertex][i]) {
					dist[i] = dist[current_vertex] + matrix[current_vertex][i];
				}
			}
		}
	}

	return;
}

#define min(a, b) (((a) > (b)) ? (b) : (a))
int main() {
	init();

	scanf("%d %d", &n, &e);
	while (e--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		matrix[a][b] = matrix[b][a] = c;
	}
	scanf("%d %d", &v1, &v2);
	start = 1, end = n;

	dijkstra(fromV1, v1);
	dijkstra(fromV2, v2);

	if (fromV1[start] < INF && fromV1[end] < INF && fromV1[v2] < INF) {
		printf("%d", min(fromV1[start] + fromV1[v2] + fromV2[end], fromV2[start] + fromV1[v2] + fromV1[end]));
	} else {
		printf("-1");
	}
	return 0;
}