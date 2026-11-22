#include <stdbool.h>
#include <stdio.h>

typedef char pipe;

#define MAX_IDX 25
#define MAX_DIR 4

const pipe START = 'M';
const pipe END = 'Z';
const pipe EMPTY = '.';
const pipe VERTICAL = '|';
const pipe HORIZONTAL = '-';
const pipe PLUS = '+';
const pipe RIGHT_DOWN = '1';
const pipe RIGHT_UP = '2';
const pipe LEFT_UP = '3';
const pipe LEFT_DOWN = '4';

const int NORTH = 0;
const int SOUTH = 1;
const int WEST = 2;
const int EAST = 3;
const int NONE = -1;

typedef struct Position {
	int x, y;
} Position;

const Position dir[MAX_DIR] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

char board[MAX_IDX][MAX_IDX];
Position start, end;
bool connected_with_start, connected_with_end;
int r, c;

bool is_same_position(Position a, Position b) {
	return (a.x == b.x && a.y == b.y);
}

void read_input() {
	scanf("%d %d", &r, &c);
	for (int x = 0; x < r; ++x) {
		scanf("%s", board[x]);
		for (int y = 0; y < c; ++y) {
			if (board[x][y] == START) {
				start = (Position){x, y};
				/* 4방향을 돌며 직접적으로 연결된 파이프가 있는지 확인 */
				int new_x, new_y;
				pipe temp;

				// 북쪽
				new_x = x + dir[NORTH].x, new_y = y + dir[NORTH].y;
				temp = board[new_x][new_y];
				connected_with_start |= (temp == VERTICAL || temp == PLUS || temp == LEFT_DOWN || temp == RIGHT_DOWN);

				// 남쪽
				new_x = x + dir[SOUTH].x, new_y = y + dir[SOUTH].y;
				temp = board[new_x][new_y];
				connected_with_start |= (temp == VERTICAL || temp == PLUS || temp == LEFT_UP || temp == RIGHT_UP);

				// 서쪽
				new_x = x + dir[WEST].x, new_y = y + dir[WEST].y;
				temp = board[new_x][new_y];
				connected_with_start |= (temp == HORIZONTAL || temp == PLUS || temp == RIGHT_DOWN || temp == RIGHT_UP);

				// 동쪽
				new_x = x + dir[EAST].x, new_y = y + dir[EAST].y;
				temp = board[new_x][new_y];
				connected_with_start |= (temp == HORIZONTAL || temp == PLUS || temp == LEFT_DOWN || temp == LEFT_UP);

			} else if (board[x][y] == END) {
				end = (Position){x, y};
				/* 4방향을 돌며 직접적으로 연결된 파이프가 있는지 확인 */
				int new_x, new_y;
				pipe temp;

				// 북쪽
				new_x = x + dir[NORTH].x, new_y = y + dir[NORTH].y;
				temp = board[new_x][new_y];
				connected_with_end |= (temp == VERTICAL || temp == PLUS || temp == LEFT_DOWN || temp == RIGHT_DOWN);

				// 남쪽
				new_x = x + dir[SOUTH].x, new_y = y + dir[SOUTH].y;
				temp = board[new_x][new_y];
				connected_with_end |= (temp == VERTICAL || temp == PLUS || temp == LEFT_UP || temp == RIGHT_UP);

				// 서쪽
				new_x = x + dir[WEST].x, new_y = y + dir[WEST].y;
				temp = board[new_x][new_y];
				connected_with_end |= (temp == HORIZONTAL || temp == PLUS || temp == RIGHT_DOWN || temp == RIGHT_UP);

				// 동쪽
				new_x = x + dir[EAST].x, new_y = y + dir[EAST].y;
				temp = board[new_x][new_y];
				connected_with_end |= (temp == HORIZONTAL || temp == PLUS || temp == LEFT_DOWN || temp == LEFT_UP);
			}
		}
	}
	return;
}

Position find_empty_position() {
	/*
	차선책 사용 : 모든 칸을 돌며 찾은 파이프에서 진행하는걸로
	시작점과 도착점에서의 시작 방향을 알지 못한다는 점이 큰 것 같음
	문제의 가정에 의해, 방향이 정해진 파이프는 적어도 1개 존재함
	*/
	for (int x = 0; x < r; ++x) {
		for (int y = 0; y < c; ++y) {
			pipe cur = board[x][y];

			/* 파이프의 4방향 모두 탐색. 이어져야하는데 이어지는 부분이 없다면, 그 공간이 빈 공간 */
			if (cur != EMPTY && cur != START && cur != END) {
				int new_x, new_y;

				// 북쪽
				if (cur == VERTICAL || cur == PLUS || cur == RIGHT_UP || cur == LEFT_UP) {
					new_x = x + dir[NORTH].x, new_y = y + dir[NORTH].y;
					if (board[new_x][new_y] == EMPTY) {
						return (Position){new_x, new_y};
					}
				}

				// 남쪽
				if (cur == VERTICAL || cur == PLUS || cur == RIGHT_DOWN || cur == LEFT_DOWN) {
					new_x = x + dir[SOUTH].x, new_y = y + dir[SOUTH].y;
					if (board[new_x][new_y] == EMPTY) {
						return (Position){new_x, new_y};
					}
				}

				// 서쪽
				if (cur == HORIZONTAL || cur == PLUS || cur == LEFT_DOWN || cur == LEFT_UP) {
					new_x = x + dir[WEST].x, new_y = y + dir[WEST].y;
					if (board[new_x][new_y] == EMPTY) {
						return (Position){new_x, new_y};
					}
				}

				// 동쪽
				if (cur == HORIZONTAL || cur == PLUS || cur == RIGHT_UP || cur == RIGHT_DOWN) {
					new_x = x + dir[EAST].x, new_y = y + dir[EAST].y;
					if (board[new_x][new_y] == EMPTY) {
						return (Position){new_x, new_y};
					}
				}
			}
		}
	}

	return (Position){NONE, NONE};
}

pipe get_answer(Position t) {
	/*
	빈칸 기준 4방향의 파이프를 탐색
	직접적으로 연결된 파이프들의 위치를 탐색 후 그 위치들을 모두 포함할 수 있는 파이프를 선택해야 함
	만약 인접 위치가 시작점 혹은 도착점인 경우 추가적인 조치가 필요함
	*/
	bool has_to_connect[MAX_DIR] = {false};
	Position cur = t;
	pipe temp;

	// 북쪽
	if (t.x > 0) {
		cur = (Position){t.x - 1, t.y};
		temp = board[cur.x][cur.y];
		has_to_connect[NORTH] = (temp == VERTICAL || temp == PLUS || temp == LEFT_DOWN || temp == RIGHT_DOWN);
		if (is_same_position(cur, start) == true) {
			has_to_connect[NORTH] |= (connected_with_start == false);
		}
		if (is_same_position(cur, end) == true) {
			has_to_connect[NORTH] |= (connected_with_end == false);
		}
	}

	// 남쪽
	if (t.x < r - 1) {
		cur = (Position){t.x + 1, t.y};
		temp = board[cur.x][cur.y];
		has_to_connect[SOUTH] = (temp == VERTICAL || temp == PLUS || temp == LEFT_UP || temp == RIGHT_UP);
		if (is_same_position(cur, start) == true) {
			has_to_connect[SOUTH] |= (connected_with_start == false);
		}
		if (is_same_position(cur, end) == true) {
			has_to_connect[SOUTH] |= (connected_with_end == false);
		}
	}

	// 서쪽
	if (t.y > 0) {
		cur = (Position){t.x, t.y - 1};
		temp = board[cur.x][cur.y];
		has_to_connect[WEST] = (temp == HORIZONTAL || temp == PLUS || temp == RIGHT_DOWN || temp == RIGHT_UP);
		if (is_same_position(cur, start) == true) {
			has_to_connect[WEST] |= (connected_with_start == false);
		}
		if (is_same_position(cur, end) == true) {
			has_to_connect[WEST] |= (connected_with_end == false);
		}
	}

	// 동쪽
	if (t.y < c - 1) {
		cur = (Position){t.x, t.y + 1};
		temp = board[cur.x][cur.y];
		has_to_connect[EAST] = (temp == HORIZONTAL || temp == PLUS || temp == LEFT_DOWN || temp == LEFT_UP);
		if (is_same_position(cur, start) == true) {
			has_to_connect[EAST] |= (connected_with_start == false);
		}
		if (is_same_position(cur, end) == true) {
			has_to_connect[EAST] |= (connected_with_end == false);
		}
	}

	// 얻은 결과를 통해 정답 도출
	if (has_to_connect[NORTH] == true && has_to_connect[SOUTH] == true) {
		if (has_to_connect[WEST] == true && has_to_connect[EAST] == true) {
			return PLUS;
		} else {
			return VERTICAL;
		}
	}
	if (has_to_connect[WEST] == true && has_to_connect[EAST] == true) {
		return HORIZONTAL;
	}
	if (has_to_connect[NORTH] == true) {
		if (has_to_connect[WEST] == true) {
			return LEFT_UP;
		} else {
			return RIGHT_UP;
		}
	}
	if (has_to_connect[SOUTH] == true) {
		if (has_to_connect[WEST] == true) {
			return LEFT_DOWN;
		} else {
			return RIGHT_DOWN;
		}
	}

	return 'x'; // 없는 파이프
}

int main() {
	connected_with_start = false, connected_with_end = false;
	read_input();
	Position empty = find_empty_position();
	pipe pipe_type = get_answer(empty);
	printf("%d %d %c\n", empty.x + 1, empty.y + 1, pipe_type);
	return 0;
}
