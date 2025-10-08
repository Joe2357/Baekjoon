#include <stdio.h>

#define MAX_LEN 100
#define MAX_GRID_HEIGHT 3

int n, j, s, h, k;

char grid[MAX_GRID_HEIGHT][MAX_LEN + 1];

#define min(a, b) (((a) > (b)) ? (b) : (a))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int main() {
	scanf("%d %d %d %d %d", &n, &j, &s, &h, &k);
	scanf("%s%s%s", grid[0], grid[1], grid[2]);

	int low_obstacle = 0, high_obstacle = 0, up_obstacle = 0;
	for (int i = 0; i < n; ++i) {
		if (grid[2][i] == '^' && grid[1][i] == '^') {
			high_obstacle += 1;
		} else if (grid[2][i] == '^' && grid[1][i] == '.') {
			low_obstacle += 1;
		} else if (grid[0][i] == 'v') {
			up_obstacle += 1;
		}
	}
	// printf("%d %d %d\n", low_obstacle, high_obstacle, up_obstacle);

	if (up_obstacle > s) {
		h -= (up_obstacle - s) * k;
	}
	if (low_obstacle > j) {
		h -= (low_obstacle - j) * k;
	}
	j = max(j - low_obstacle, 0);
	if (high_obstacle > j / 2) {
		h -= (high_obstacle - j / 2) * k;
	}

	printf("%d", (h > 0) ? h : -1);
	return 0;
}