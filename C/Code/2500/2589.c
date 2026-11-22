#include <stdbool.h>
#include <stdio.h>

#define MAX_IDX 50
const char LAND = 'L';
const char WATER = 'W';
#define MAX_DIR 4

typedef struct Position {
	int x, y;
} Position;
typedef struct QueueNode {
	Position pos;
	int distance;
} QueueNode;

const Position dir[MAX_DIR] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

char grid[MAX_IDX][MAX_IDX + 1];
int n, m;

QueueNode q[MAX_IDX * MAX_IDX];
int front, rear;

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

bool is_valid(Position pos) {
	if (pos.x < 0 || pos.x >= n || pos.y < 0 || pos.y >= m) {
		return false;
	}
	if (grid[pos.x][pos.y] == WATER) {
		return false;
	}
	return true;
}

void read_input() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%s", grid[i]);
	}
	return;
}

int get_max_distance(int x, int y) {
	bool visited[MAX_IDX][MAX_IDX] = {false};
	front = rear = 0;

	visited[x][y] = true;
	q[rear++] = (QueueNode){{x, y}, 0};

	int max_distance = 0;
	while (front < rear) {
		QueueNode curr = q[front++];
		max_distance = max(max_distance, curr.distance);

		for (int i = 0; i < MAX_DIR; ++i) {
			Position next_pos = {curr.pos.x + dir[i].x, curr.pos.y + dir[i].y};

			if (is_valid(next_pos) == true && visited[next_pos.x][next_pos.y] == false) {
				visited[next_pos.x][next_pos.y] = true;
				q[rear++] = (QueueNode){next_pos, curr.distance + 1};
			}
		}
	}
	return max_distance;
}

int main() {
	read_input();

	int max_distance = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (grid[i][j] == LAND) {
				int temp = get_max_distance(i, j);
				max_distance = max(max_distance, temp);
			}
		}
	}
	printf("%d", max_distance);
	return 0;
}