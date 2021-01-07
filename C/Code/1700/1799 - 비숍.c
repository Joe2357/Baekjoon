#include <stdio.h>

typedef char boolean;

#define MAX_INDEX 10
int n;
boolean grid[MAX_INDEX][MAX_INDEX];
int result;

#define max(a, b) (((a) > (b)) ? (a) : (b))
void dfs(int *left, int *right, int len, int used)
{
	if (len == n * 2)
	{
		result = max(result, used);
		return;
	}

	if (len < n)
	{
		for (int i = 0; i <= len; ++i)
		{
			if (grid[len - i][i] &&)
		}
	}
	else
	{
		for (int i = 2 * n - len - 1; i >= 0; --i)
		{
		}
	}

	dfs(left, right, len + 1);
}

void read_input()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &grid[i][j]);
	return;
}
void solve()
{
	int left[MAX_INDEX * 2],
		right[MAX_INDEX * 2];
	for (int i = 0; i < MAX_INDEX * 2; ++i)
		left[i] = right[i] = -1;

	dfs(left, right, 0);
	return;
}
void print_result()
{
	printf("%d", result);
	return;
}

int main()
{
	read_input();
	solve();
	print_result();
	return 0;
}