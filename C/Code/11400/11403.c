#include <stdio.h>

int path[101][101],
	cango[101][101],
	n;

int main() {
	scanf("%d", &n);

	// input
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &path[i][j]);

	for (int start = 1; start <= n; start++) {
		// bfs search
		int queue[10000] = {0}, front = 0, rear = 0, visited[101] = {0};
		for (int a = 1; a <= n; a++)
			if (path[start][a])
				queue[rear++] = a,
				cango[start][a] = 1,
				rear %= 10000;

		while (front != rear) {
			int temp = queue[front++];
			if (!visited[temp]) {
				visited[temp] = 1,
				cango[start][temp] = 1;
				for (int a = 1; a <= n; a++)
					if (path[temp][a])
						queue[rear++] = a,
						cango[temp][a] = 1;
			}
			front %= 10000;
		}
	}

	// output
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			printf("%d ", cango[i][j]);
		printf("\n");
	}
	return 0;
}