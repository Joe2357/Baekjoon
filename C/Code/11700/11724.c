#include <stdio.h>
#define MAX_VERTAX 1000

int way[MAX_VERTAX][MAX_VERTAX],
	visited[MAX_VERTAX], result;

int main(n, m) {
	for (scanf("%d %d", &n, &m); m; m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		way[a - 1][b - 1] = 1, way[b - 1][a - 1] = 1;
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = 1, result++;
			int queue[MAX_VERTAX * MAX_VERTAX] = {0},
								   front = 0, rear = 0;
			for (int a = 0; a < MAX_VERTAX; a++)
				if (way[i][a])
					queue[rear++] = a;
			while (front != rear) {
				int temp = queue[front++];
				if (!visited[temp]) {
					visited[temp] = 1;
					for (int a = 0; a < MAX_VERTAX; a++)
						if (way[temp][a])
							queue[rear++] = a;
				}
			}
		}
	}
	printf("%d", result);
	return 0;
}