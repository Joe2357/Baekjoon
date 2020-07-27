#include <stdio.h>
#define max(a, b) (a > b) ? a : b

typedef struct Position {
	int x, y;
} PS;

int grid[8][8],
zeroCount, result, n, m;

void BFS() { // spread every virus
	int arr[8][8] = { 0 },
		front = 0, rear = 0,
		tempZero = zeroCount;

	// BFS
	PS queue[1000] = { 0 };
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			arr[i][j] = grid[i][j];
			if (arr[i][j] == 2)
				queue[rear].x = j,
				queue[rear++].y = i;
		}
	while (front != rear) {
		PS temp = queue[front++];
		if (0 <= temp.x && 0 <= temp.y && temp.y < n && temp.x < m) {
			if (!(arr[temp.y][temp.x] % 2))
				tempZero -= (!arr[temp.y][temp.x]),
				arr[temp.y][temp.x] = 3,
				queue[rear].y = temp.y - 1, queue[rear++].x = temp.x,
				queue[rear].y = temp.y + 1, queue[rear++].x = temp.x,
				queue[rear].y = temp.y, queue[rear++].x = temp.x - 1,
				queue[rear].y = temp.y, queue[rear++].x = temp.x + 1;
		}
	}

	// find the biggest safe-zone count
	result = max(result, tempZero);
	return;
}

void getResult() { // make 3 walls using brute force, and spread all virus
	for (int i = 0; i < n * m; i++)
		if (!grid[i / m][i % m]) {
			grid[i / m][i % m] = 1; // 1st wall
			for (int j = i + 1; j < n * m; j++)
				if (!grid[j / m][j % m]) {
					grid[j / m][j % m] = 1; // 2nd wall
					for (int k = j + 1; k < n * m; k++)
						if (!grid[k / m][k % m]) {
							grid[k / m][k % m] = 1; // 3rd wall
							BFS();					// spread virus
							grid[k / m][k % m] = 0; // remove 3rd wall
						}
					grid[j / m][j % m] = 0; // remove 2nd wall
				}
			grid[i / m][i % m] = 0; // remove 1st wall
		}
	return;
}

int main() {
	// init
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%d", &grid[i][j]);
			zeroCount += (!grid[i][j]);
		}

	zeroCount -= 3; // will make 3 walls

	// bfs result find
	getResult();

	// print result
	printf("%d", result);
	return 0;
}