#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef struct Position {
	int x, y;
} Position;

#define MAX_IDX 1000
const char EMPTY = '.';
const char WALL = '#';
const char START = '@';
const char FIRE = '*';
const int NONE = -1;

#define MAX_DIR 4
const Position directions[MAX_DIR] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

char grid[MAX_IDX][MAX_IDX + 1];
int w, h; // 가로, 세로가 반대로 주어짐

Position fire_queue[MAX_IDX * MAX_IDX];
int fire_front, fire_rear;
Position player_queue[MAX_IDX * MAX_IDX];
bool visited[MAX_IDX][MAX_IDX + 1];
int player_front, player_rear;

void init() {
	fire_front = fire_rear = 0;
	player_front = player_rear = 0;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			visited[i][j] = false;
		}
	}

	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if (grid[i][j] == START) {
				visited[i][j] = true;
				player_queue[player_rear++] = (Position){i, j};
				grid[i][j] = EMPTY;
			}
			if (grid[i][j] == FIRE) {
				fire_queue[fire_rear++] = (Position){i, j};
			}
		}
	}
	return;
}

void spread_fire() {
	int current_fire_rear = fire_rear;
	for (int i = fire_front; i < current_fire_rear; ++i) {
		Position pos = fire_queue[i];
		for (int d = 0; d < MAX_DIR; ++d) {
			int nx = pos.x + directions[d].x;
			int ny = pos.y + directions[d].y;
			if (0 <= nx && nx < h && 0 <= ny && ny < w && grid[nx][ny] == EMPTY) {
				grid[nx][ny] = FIRE;
				fire_queue[fire_rear++] = (Position){nx, ny};
			}
		}
	}
	fire_front = current_fire_rear;
	return;
}

bool move_player() {
	int current_player_rear = player_rear;
	for (int i = player_front; i < current_player_rear; ++i) {
		Position pos = player_queue[i];
		for (int d = 0; d < MAX_DIR; ++d) {
			int nx = pos.x + directions[d].x;
			int ny = pos.y + directions[d].y;
			if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
				return true;
			}

			if (grid[nx][ny] == EMPTY && visited[nx][ny] == false) {
				visited[nx][ny] = true;
				player_queue[player_rear++] = (Position){nx, ny};
			}
		}
	}
	player_front = current_player_rear;
	return false;
}

int solve() {
	init();
	int time;
	for (time = 1; true; ++time) {
		spread_fire();
		if (move_player() == true) {
			break;
		} else if (player_front == player_rear) {
			time = NONE;
			break;
		}
	}
	return time;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &w, &h);
		for (int i = 0; i < h; ++i) {
			scanf("%s", grid[i]);
		}
		int ret;
		if ((ret = solve()) == NONE) {
			printf("IMPOSSIBLE\n");
		} else {
			printf("%d\n", ret);
		}
	}
	return 0;
}