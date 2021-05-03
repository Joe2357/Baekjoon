#include <stdio.h>

typedef char boolean;
#define True 1
#define False 0
typedef struct Node {
	int x, y;
	int c;
} ND;

#define DONE 1
#define NOTDONE 0
#define WALL -1
#define MAX_INDEX 1000
#define INF 987654321

ND queue[MAX_INDEX * MAX_INDEX];
int day[MAX_INDEX][MAX_INDEX];
int front = -1, rear = -1;
ND pos[4] = { {1, 0},{-1, 0}, {0, 1}, {0, -1} };
boolean visited[MAX_INDEX][MAX_INDEX + 1] = { False };

#define min(a, b) (((a) > (b)) ? (b) : (a))
#define max(a, b) (((a) > (b)) ? (a) : (b))
int main() {
	int n, m;
	scanf("%d %d", &m, &n);
	char grid[MAX_INDEX][MAX_INDEX + 1];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int a;
			scanf("%d", &a);
			grid[i][j] = a;
			if (a == DONE) {
				queue[++rear] = (ND) { i, j, 0 };
				visited[i][j] = True;
			}
			else if (a == NOTDONE) {
				day[i][j] = INF;
			}
		}
	}

	while (front < rear) {
		ND cur = queue[++front];

		for (int i = 0; i < 4; ++i) {
			ND temp = (ND) { cur.x + pos[i].x, cur.y + pos[i].y, cur.c + 1 };
			if (temp.x < 0 || temp.y < 0 || temp.x == n || temp.y == m || grid[temp.x][temp.y] == WALL || visited[temp.x][temp.y]) {
				continue;
			}

			visited[temp.x][temp.y] = True;
			day[temp.x][temp.y] = temp.c;
			queue[++rear] = temp;
		}
	}

	int result = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			result = max(result, day[i][j]);
		}
	}

	if (result == INF) {
		printf("-1");
	}
	else {
		printf("%d", result);
	}
	return 0;
}