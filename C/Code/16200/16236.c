#include <stdio.h>

#define MAX_IDX 20
#define True 1
#define False 0
#define INF 987654321

typedef char boolean;
typedef struct Position {
	int x, y;
	int d;
} PS;

int grid[MAX_IDX][MAX_IDX];
int n;
int cur_size = 2, cur_ate = 0;
int result;
PS cur;
PS pos[4] = { {-1,0},{0,-1},{0,1},{1,0} };

#define abs(x) ((x < 0) ? (-(x)) : (x))
#define min(a, b) (((a) > (b)) ? (b) : (a))

int getDistance(PS x) {
	PS queue[MAX_IDX * MAX_IDX] = { x };
	boolean visited[MAX_IDX][MAX_IDX + 1] = { False };
	visited[x.x][x.y] = True;
	int front = 0, rear = 1;

	while (front < rear) {
		PS node = queue[front++];

		for (int i = 0; i < 4; ++i) {
			PS a = { node.x + pos[i].x, node.y + pos[i].y, node.d + 1 };

			if (a.x < 0 || a.x == n || a.y < 0 || a.y == n || visited[a.x][a.y]) {

			}
			else {
				visited[a.x][a.y] = True;
				if (a.x == cur.x && a.y == cur.y) {
					return a.d;
				}
				else if (grid[a.x][a.y] <= cur_size) {
					queue[rear++] = a;
				}
			}
		}
	}

	return INF;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &grid[i][j]);
			if (grid[i][j] == 9) {
				cur = (PS) { i, j };
				grid[i][j] = 0;
			}
		}
	}

	while (True) {
		PS next = { -1, -1, INF };
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (0 < grid[i][j] && grid[i][j] < cur_size) {
					int tempDist = getDistance((PS) { i, j, 0 });
					if (tempDist < next.d) {
						next = (PS) { i, j, tempDist };
					}
				}
			}
		}

		if (next.d < INF) {
			result += next.d;
			cur = next;
			grid[cur.x][cur.y] = 0;
			if (++cur_ate == cur_size) {
				++cur_size, cur_ate = 0;
			}
		}
		else {
			break;
		}
	}

	printf("%d", result);
	return 0;
}