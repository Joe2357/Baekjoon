#include <stdio.h>

typedef struct Position {
	int x, y;
} PS;
typedef struct Path {
	int w;
	int s, e;
} Path;

typedef char boolean;
#define True 1
#define False 0

#define MAX_IDX 10
#define MAX_CITY 6
#define INF 10000

int n, m;
int grid[MAX_IDX][MAX_IDX];
int matrix[MAX_CITY + 1][MAX_CITY + 1];
Path path[MAX_CITY * MAX_CITY]; int len;
boolean input[MAX_IDX][MAX_IDX + 1];
int groupCount;
int parent[MAX_CITY + 1];
PS dir[4] = { {1,0},{-1,0},{0,1},{0,-1} };

#define min(a, b) (((a) > (b)) ? (b) : (a))

void makeGroup(PS a) {
	if (a.x < 0 || a.x >= n || a.y < 0 || a.y >= m) {
		return;
	}
	if (input[a.x][a.y]) {
		grid[a.x][a.y] = groupCount;
		input[a.x][a.y] = False;
		for (int i = 0; i < 4; ++i) {
			makeGroup((PS) { a.x + dir[i].x, a.y + dir[i].y });
		}
	}
	return;
}

void makeBridge(PS cur, int mode, int s, int c) {
	int e;
	if (cur.x < 0 || cur.x >= n || cur.y < 0 || cur.y >= m) {
	}
	else if (grid[cur.x][cur.y] == s) {
	}
	else if (grid[cur.x][cur.y] != 0) {
		if (c == 1) {

		}
		else {
			int e = grid[cur.x][cur.y];
			matrix[s][e] = min(matrix[s][e], c);
			matrix[e][s] = min(matrix[e][s], c);
		}
	}
	else {
		makeBridge((PS) { cur.x + dir[mode].x, cur.y + dir[mode].y }, mode, s, c + 1);
	}
	return;
}

int cmp(Path* a, Path* b) {
	return a->w > b->w;
}

int find(int x) {
	if (parent[x] == x) {
		return x;
	}
	else {
		return parent[x] = find(parent[x]);
	}
}

boolean merge(int a, int b) {
	int x = find(a), y = find(b);

	if (x == y) {
		return False;
	}
	else {
		if (x > y) {
			parent[a] = parent[x] = y;
		}
		else {
			parent[b] = parent[y] = x;
		}
		return True;
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int a;
			scanf("%d", &a);
			input[i][j] = a;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (input[i][j] == True) {
				++groupCount;
				makeGroup((PS) { i, j });
			}
		}
	}

	for (int i = 1; i <= groupCount; ++i) {
		parent[i] = i;
		for (int j = 1; j <= groupCount; ++j) {
			matrix[i][j] = INF * (i != j);
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (grid[i][j] != 0) {
				for (int a = 0; a < 4; ++a) {
					makeBridge((PS) { i + dir[a].x, j + dir[a].y }, a, grid[i][j], 0);
				}
			}
		}
	}

	for (int i = 1; i <= groupCount; ++i) {
		for (int j = i + 1; j <= groupCount; ++j) {
			if (matrix[i][j] > 0 && matrix[i][j] < INF) {
				path[len++] = (Path) { matrix[i][j], i, j };
			}
		}
	}
	qsort(path, len, sizeof(Path), cmp);

	int merged = 1;
	int result = 0;
	for (int i = 0; i < len; ++i) {
		Path a = path[i];

		if (merge(a.s, a.e)) {
			result += a.w;
			if (++merged == groupCount) {
				printf("%d", result);
				return 0;
			}
		}
	}

	printf("-1");
	return 0;
}