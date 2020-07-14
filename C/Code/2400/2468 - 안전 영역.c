#include <stdio.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) > (b)) ? (b) : (a))

typedef struct Position {
	int x, y;
} POS;

int n, grid[100][100], result = 1;
int ps[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

void BFS(int height) {
	int visited[100][100] = { 0 },
		tempResult = 0;
	// brute force
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// BFS search
			if (!visited[i][j] && grid[i][j] > height) {
				visited[i][j] = 1, tempResult++;
				POS queue[10000] = { 0 };
				int front = 0, rear = 0;
				for (int a = 0; a < 4; a++)
					if (i + ps[a][1] < n && j + ps[a][0] < n && i + ps[a][1] >= 0 && j + ps[a][0] >= 0)
						if (!visited[i + ps[a][1]][j + ps[a][0]]) {
							visited[i + ps[a][1]][j + ps[a][0]] = 1;
							queue[rear].x = j + ps[a][0], queue[rear].y = i + ps[a][1], rear++, rear %= 10000;
						}
				// queue loop
				while (front != rear) {
					POS temp = queue[front++];
					front %= 10000;
					if (grid[temp.y][temp.x] > height)
						for (int a = 0; a < 4; a++)
							if (temp.y + ps[a][1] < n && temp.x + ps[a][0] < n && temp.y + ps[a][1] >= 0 && temp.x + ps[a][0] >= 0)
								if (!visited[temp.y + ps[a][1]][temp.x + ps[a][0]]) {
									visited[temp.y + ps[a][1]][temp.x + ps[a][0]] = 1;
									queue[rear].x = temp.x + ps[a][0], queue[rear].y = temp.y + ps[a][1], rear++, rear %= 10000;
								}
				}
			}
		}
	}
	// renew result
	result = max(result, tempResult);
	return;
}

int main() {
	scanf("%d", &n);
	int maxValue = -1, minValue = 101;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &grid[i][j]);
			maxValue = max(maxValue, grid[i][j]),
				minValue = min(minValue, grid[i][j]);
		}
	for (; minValue < maxValue; minValue++)
		BFS(minValue);
	printf("%d", result);
	return 0;
}