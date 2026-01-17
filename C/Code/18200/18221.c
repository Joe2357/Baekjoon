#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 1000
const int MIN_DIST = 5;
const int MIN_STUDENT = 3;
const int EMPTY = 0, OTHERS = 1, TARGET = 2, PROFESSOR = 5;

typedef struct Position {
	int x, y;
} Position;

int grid[MAX_IDX][MAX_IDX];
int n;
Position target, professor;

#define min(a, b) (((a) > (b)) ? (b) : (a))
#define max(a, b) (((a) > (b)) ? (a) : (b))

void read_input() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &grid[i][j]);

			if (grid[i][j] == TARGET) {
				target = (Position){i, j};
			} else if (grid[i][j] == PROFESSOR) {
				professor = (Position){i, j};
			}
		}
	}
	return;
}

int get_double_distance() {
	int x = target.x - professor.x, y = target.y - professor.y;
	return (x * x + y * y);
}

int get_student_cnt() {
	int min_x = min(target.x, professor.x), max_x = max(target.x, professor.x);
	int min_y = min(target.y, professor.y), max_y = max(target.y, professor.y);

	int student_cnt = 0;
	for (int i = min_x; i <= max_x; ++i) {
		for (int j = min_y; j <= max_y; ++j) {
			student_cnt += (grid[i][j] == OTHERS);
		}
	}
	return student_cnt;
}

int main() {
	read_input();
	printf("%d", (get_double_distance() >= (MIN_DIST * MIN_DIST)) && (get_student_cnt() >= MIN_STUDENT));
	return 0;
}