#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 500
const char EMPTY = '0', FILLED = '1';
const int NONE = -1;

char grid[MAX_IDX][MAX_IDX + 1];
int rows[MAX_IDX], cols[MAX_IDX];
bool visited[MAX_IDX + 1];
int n;

void read_input() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &rows[i]);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &cols[i]);
	}
	return;
}

int sum(int* arr, int size) {
	int total = 0;
	for (int i = 0; i < size; ++i) {
		total += arr[i];
	}
	return total;
}

void grid_init() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			grid[i][j] = EMPTY;
		}
	}
	return;
}

void print_grid() {
	for (int i = 0; i < n; ++i) {
		printf("%s\n", grid[i]);
	}
	return;
}

void visit_init() {
	for (int i = 0; i < n; ++i) {
		visited[i] = false;
	}
	return;
}

bool make_grid() {
	// 모든 row에 대하여, 값이 가장 높은 col부터 채워나가기
	for (int i = 0; i < n; ++i) {
		visit_init();

		while (rows[i] > 0) {
			int max_col_idx = NONE, max_col_val = NONE;
			for (int j = 0; j < n; ++j) {
				if (visited[j] == false && cols[j] > max_col_val) {
					max_col_idx = j, max_col_val = cols[j];
				}
			}
			if (max_col_idx == NONE || max_col_val == 0) {
				return false;
			}

			visited[max_col_idx] = true;
			grid[i][max_col_idx] = FILLED;
			rows[i] -= 1, cols[max_col_idx] -= 1;
		}
	}
	return true;
}

int main() {
	read_input();

	if (sum(rows, n) != sum(cols, n)) {
		printf("-1");
	} else {
		grid_init();

		/* logic */
		bool isPossible = make_grid();
		/* end of logic */

		if (isPossible == false) {
			printf("-1");
		} else {
			printf("1\n");
			print_grid();
		}
	}

	return 0;
}