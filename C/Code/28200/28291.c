#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef struct Direction {
	int x, y;
} DIR;
typedef struct QueueNode {
	DIR pos;
	int power;
} QN;

#define MAX_DIR 4
#define MAX_SIZE 50
const int DUST = 1;
const int BLOCK = 2;
const int LAMP = 3;
const int BLOCK_POWER = 16; // 문제에서 "블록의 인접한 칸"의 파워가 15라고 하였으므로, 블록의 파워를 16으로 계산 가능
const int NONE = 0;

const DIR dir[MAX_DIR] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int grid[MAX_SIZE][MAX_SIZE + 1];
int power_grid[MAX_SIZE][MAX_SIZE];
int w, h, n;

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) > (b)) ? (b) : (a))

void read_input() {
	scanf("%d %d %d", &w, &h, &n);

	char name[15];
	int x, y;
	while (n--) {
		scanf("%s %d %d", name, &x, &y);
		switch (name[9]) {
			case 'd': { // dust
				grid[x][y] = DUST;
				break;
			}
			case 'b': { // block
				grid[x][y] = BLOCK;
				break;
			}
			case 'l': { // lamp
				grid[x][y] = LAMP;
				break;
			}
		}
	}
	return;
}

void update_grid_power() {
	QN queue[MAX_SIZE * MAX_SIZE + 1];
	int front = 0, rear = 0;

	for (int x = 0; x < w; ++x) {
		for (int y = 0; y < h; ++y) {
			if (grid[x][y] == BLOCK) {
				power_grid[x][y] = BLOCK_POWER;
				queue[rear++] = (QN){(DIR){x, y}, BLOCK_POWER};
			}
		}
	}

	while (front < rear) {
		QN node = queue[front++];
		if (node.power < 1) {
			break;
		}
		if (grid[node.pos.x][node.pos.y] == LAMP) {
			continue;
		}

		for (int i = 0; i < MAX_DIR; ++i) {
			DIR newPos = (DIR){node.pos.x + dir[i].x, node.pos.y + dir[i].y};
			if (0 <= newPos.x && newPos.x < w && 0 <= newPos.y && newPos.y < h) {
				if (grid[newPos.x][newPos.y] == DUST || grid[newPos.x][newPos.y] == LAMP) {
					if (power_grid[newPos.x][newPos.y] == NONE) {
						power_grid[newPos.x][newPos.y] = node.power - 1;
						queue[rear++] = (QN){newPos, node.power - 1};
					}
				}
			}
		}
	}

	return;
}

bool solve() {
	bool isAllLampTurnOn = true;
	for (int x = 0; x < w; ++x) {
		for (int y = 0; y < h; ++y) {
			if (grid[x][y] == LAMP) {
				isAllLampTurnOn &= (power_grid[x][y] > NONE);
			}
		}
	}
	return isAllLampTurnOn;
}

int main() {
	read_input();
	update_grid_power();

	printf("%s", (solve() == true) ? "success" : "failed");
	return 0;
}