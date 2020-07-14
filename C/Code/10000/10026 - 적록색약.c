#include <stdio.h>
#define MAX_INDEX 100
#define True 1
#define False 0

typedef char boolean;

// 0 : Not red-green, 1 : red-green
char grid[MAX_INDEX][MAX_INDEX + 1];
boolean visited[MAX_INDEX][MAX_INDEX][2];
int n;
int ret[2];

void DFS(int x, int y, boolean mode, char character) {
	if (x < 0 || y < 0 || x == n || y == n) // out of grid
		return;
	if (!visited[x][y][mode]) { // if not visited, delete all near same parts
		if (mode) { // if red-green
			if ((grid[x][y] == character) ||
				(character == 'G' && grid[x][y] == 'R') ||
				(character == 'R' && grid[x][y] == 'G')) { // if target
				visited[x][y][mode] = True;
				DFS(x - 1, y, mode, character);
				DFS(x + 1, y, mode, character);
				DFS(x, y - 1, mode, character);
				DFS(x, y + 1, mode, character);
			}
		}
		else { // if non red-green
			if (grid[x][y] == character) { // if target
				visited[x][y][mode] = True;
				DFS(x - 1, y, mode, character);
				DFS(x + 1, y, mode, character);
				DFS(x, y - 1, mode, character);
				DFS(x, y + 1, mode, character);
			}
		}
	}
	return;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%s", grid[i]);

	// Non red-green
	for (int x = 0; x < n; x++)
		for (int y = 0; y < n; y++)
			if (!visited[x][y][False]) {
				ret[False]++;
				DFS(x, y, False, grid[x][y]);
			}

	// red-green
	for (int x = 0; x < n; x++)
		for (int y = 0; y < n; y++)
			if (!visited[x][y][True]) {
				ret[True]++;
				DFS(x, y, True, grid[x][y]);
			}

	// print result
	printf("%d %d", ret[0], ret[1]);
	return 0;
}