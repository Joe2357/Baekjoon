#include <stdio.h>
#define MAX_INDEX 50
#define True 1
#define False 0
#define WALL 2

typedef char boolean;
typedef struct Position {
	int x, y, d;
} PS;

int n, m, r, c, d, result,
grid[MAX_INDEX][MAX_INDEX];
boolean visited[MAX_INDEX][MAX_INDEX];
PS dir[4] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

int main() {
	// init
	PS robot;
	scanf("%d %d %d %d %d", &n, &m, &robot.x, &robot.y, &robot.d);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &grid[i][j]), visited[i][j] = grid[i][j] * 2;

	// loop simulator
	int rotated = 0;
	boolean loop = True;
	while (loop) {
		//printf("%d %d %d\n", robot.x, robot.y, robot.d);

		// wipe if not wiped
		if (!visited[robot.x][robot.y])
			visited[robot.x][robot.y] = True, result++;

		// check whether robot can't wipe 4 places
		boolean leftOver = False;
		for (int i = 1; i <= 4; i++) {
			int temp = robot.d - i;
			temp += (4 * (temp < 0));
			if (!visited[robot.x + dir[temp].x][robot.y + dir[temp].y]) {
				robot.x += dir[temp].x, robot.y += dir[temp].y, robot.d = temp;
				leftOver = True;
				break;
			}
		}
		if (leftOver)
			continue;

		// move backward if back is not a wall
		int temp = robot.d + 2;
		temp -= (4 * (temp >= 4));
		if (visited[robot.x + dir[temp].x][robot.y + dir[temp].y] != WALL) {
			robot.x += dir[temp].x, robot.y += dir[temp].y;
			continue;
		}

		// no more move ( back is wall )
		loop = False;
	}

	// print result
	printf("%d", result);
	return 0;
}