#include <stdio.h>
#define max(a, b) (a > b) ? a : b
#define MAX_INDEX 500
#define True 1
#define False 0

typedef char boolean;
typedef struct Postion {
	int x, y;
} PS;

int grid[MAX_INDEX][MAX_INDEX],
n, m, result = -1;
PS tetromino[19][4] = {

	// ㅁ
	// ㅁ
	// ㅁㅁ
	{{0, 0}, {1, 0}, {2, 0}, {2, 1}},
	{{0, 0}, {1, 0}, {0, 1}, {0, 2}},
	{{0, 0}, {0, 1}, {1, 1}, {2, 1}},
	{{1, 0}, {1, 1}, {1, 2}, {0, 2}},

	{{0, 1}, {1, 1}, {2, 1}, {2, 0}},
	{{0, 0}, {1, 0}, {1, 1}, {1, 2}},
	{{0, 0}, {0, 1}, {1, 0}, {2, 0}},
	{{0, 0}, {0, 1}, {0, 2}, {1, 2}},

	// ㅁ
	// ㅁㅁ
	//   ㅁ
	{{0, 0}, {1, 0}, {1, 1}, {2, 1}},
	{{1, 0}, {1, 1}, {0, 1}, {0, 2}},
	{{0, 1}, {1, 1}, {1, 0}, {2, 0}},
	{{0, 0}, {0, 1}, {1, 1}, {1, 2}},

	// ㅁ
	// ㅁㅁ
	// ㅁ
	{{0, 0}, {0, 1}, {0, 2}, {1, 1}},
	{{0, 1}, {1, 0}, {1, 1}, {2, 1}},
	{{0, 1}, {1, 0}, {1, 1}, {1, 2}},
	{{0, 0}, {1, 0}, {1, 1}, {2, 0}},

	// ㅁㅁㅁㅁ
	{{0, 0}, {1, 0}, {2, 0}, {3, 0}},
	{{0, 0}, {0, 1}, {0, 2}, {0, 3}},

	// ㅁㅁ
	// ㅁㅁ
	{{0, 0}, {1, 0}, {0, 1}, {1, 1}},
};

int main() {
	// init
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &grid[i][j]);

	// brute force algorithm
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) { // loop all points
			PS cur = { i, j };

			// check all tetrominos
			for (int a = 0; a < 19; a++) {
				// check whether all blocks are not out of grid
				boolean isValid = True;
				int width = 0;
				for (int b = 0; b < 4; b++) {
					// make new position
					PS temp = cur;
					temp.x += tetromino[a][b].x, temp.y += tetromino[a][b].y;

					// check whether it is valid position
					if (temp.x >= 0 && temp.x < n && temp.y >= 0 && temp.y < m)
						width += grid[temp.x][temp.y];
					else {
						isValid = False;
						break;
					}
				}
				if (isValid) // update the biggest value
					result = max(result, width);
			}
		}
	}

	// print result
	printf("%d", result);
	return 0;
}