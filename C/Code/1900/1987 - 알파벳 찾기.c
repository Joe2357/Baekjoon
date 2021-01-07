#include <stdio.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define MAX_INDEX 20

typedef char boolean;
#define True 1
#define False 0

typedef struct Position
{
	int x, y;
	int visit;
	int count;
} PS;

char grid[MAX_INDEX][MAX_INDEX + 1];
int n, m;
int dx[4] = {1, -1, 0, 0},
	dy[4] = {0, 0, 1, -1};
int result;

void dfs(PS cur)
{
	if (cur.x < 0 || cur.x == n || cur.y < 0 || cur.y == m || (cur.visit & (1 << (grid[cur.x][cur.y] - 'A'))) > 0)
	{
		result = max(result, cur.count);
		return;
	}

	cur.visit |= (1 << (grid[cur.x][cur.y] - 'A'));
	for (int i = 0; i < 4; ++i)
		dfs((PS){cur.x + dx[i], cur.y + dy[i], cur.visit, cur.count + 1});

	return;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%s", grid + i);

	dfs((PS){0, 0, 0, 0});

	printf("%d", result);
	return 0;
}
