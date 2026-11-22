#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef char state;

#define MAX_GRID 100
#define MAX_OPERATION 100
const state EMPTY = 0;
const state SNAKE = '1';
const state APPLE = '2';

#define RIGHT 0
#define DOWN 1
#define LEFT 2
#define UP 3

typedef struct Position {
	int x, y;
} Position;
typedef struct Snake {
	Position pos;
	int dir;
	struct Snake* next;
} Snake;
typedef struct Operation {
	int time;
	char direction;
} Operation;

state grid[MAX_GRID][MAX_GRID + 1];
int n, k;
Operation op[MAX_OPERATION];
int l, current_operation;

Snake *head, *tail;

void read_input() {
	scanf("%d %d", &n, &k);
	while (k--) {
		int x, y;
		scanf("%d %d", &x, &y);
		grid[x - 1][y - 1] = APPLE;
	}
	scanf("%d", &l);
	for (int i = 0; i < l; ++i) {
		scanf("%d %c", &op[i].time, &op[i].direction);
	}
	return;
}

void init() {
	Snake* newNode = (Snake*)malloc(sizeof(Snake));
	newNode->pos = (Position){0, 0};
	newNode->dir = 0; // 오른쪽 시작
	newNode->next = NULL;
	head = tail = newNode;
	grid[0][0] = SNAKE;

	// qsort(op, l, sizeof(Operation), time_asc);
	current_operation = 0;
	return;
}

Position find_next_position() {
	switch (head->dir) {
		case RIGHT: {
			return (Position){head->pos.x, head->pos.y + 1};
		}
		case DOWN: {
			return (Position){head->pos.x + 1, head->pos.y};
		}
		case LEFT: {
			return (Position){head->pos.x, head->pos.y - 1};
		}
		case UP: {
			return (Position){head->pos.x - 1, head->pos.y};
		}
	}
}

bool is_valid_position(Position c) {
	return (0 <= c.x && c.x < n && 0 <= c.y && c.y < n && grid[c.x][c.y] != SNAKE);
}

int main() {
	read_input();
	init();
	int time;

	for (time = 1; true; ++time) {
		Position new_head = find_next_position(); // 먼저 뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다

		if (is_valid_position(new_head) == false) { // 만약 벽이나 자기자신의 몸과 부딪히면 게임이 끝난다
			break;
		}

		// 머리 노드 만들기
		Snake* newNode = (Snake*)malloc(sizeof(Snake));
		newNode->pos = new_head;
		newNode->dir = head->dir;
		newNode->next = NULL;
		head->next = newNode;
		head = newNode;

		if (grid[new_head.x][new_head.y] == APPLE) { // 만약 이동한 칸에 사과가 있다면, 그 칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다

		} else { // 만약 이동한 칸에 사과가 없다면, 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다
			grid[tail->pos.x][tail->pos.y] = EMPTY;
			tail = tail->next;
		}
		grid[new_head.x][new_head.y] = SNAKE;

		// 방향전환 시퀀스
		if (current_operation < l && op[current_operation].time == time) {
			if (op[current_operation].direction == 'D') {
				head->dir = (head->dir + 1) % 4;
			} else {
				head->dir = (head->dir + 3) % 4;
			}
			current_operation += 1;
		}
	}

	printf("%d", time);
	return 0;
}