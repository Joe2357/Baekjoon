#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 5
const int BINGO_THRESHOLD = 3;

int bingo_board[MAX_IDX][MAX_IDX];
bool marked[MAX_IDX][MAX_IDX];

void read_input() {
	for (int i = 0; i < MAX_IDX; ++i) {
		for (int j = 0; j < MAX_IDX; ++j) {
			scanf("%d", &bingo_board[i][j]);
			marked[i][j] = false;
		}
	}
	return;
}

bool is3Bingo() {
	int bingo_cnt = 0;

	// row bingo check
	for (int i = 0; i < MAX_IDX; ++i) {
		bool row_bingo = true;
		for (int j = 0; j < MAX_IDX; ++j) {
			row_bingo &= marked[i][j];
		}
		bingo_cnt += (row_bingo == true);
	}

	// col bingo check
	for (int i = 0; i < MAX_IDX; ++i) {
		bool col_bingo = true;
		for (int j = 0; j < MAX_IDX; ++j) {
			col_bingo &= marked[j][i];
		}
		bingo_cnt += (col_bingo == true);
	}

	// diagonal bingo check
	bool diag1_bingo = true;
	bool diag2_bingo = true;
	for (int i = 0; i < MAX_IDX; ++i) {
		diag1_bingo &= marked[i][i];
		diag2_bingo &= marked[i][MAX_IDX - 1 - i];
	}
	bingo_cnt += (diag1_bingo == true);
	bingo_cnt += (diag2_bingo == true);

	return (bingo_cnt >= BINGO_THRESHOLD);
}

int main() {
	read_input();
	for (int num = 1; num <= MAX_IDX * MAX_IDX; ++num) {
		int called_number;
		scanf("%d", &called_number);

		// mark the called number
		for (int i = 0; i < MAX_IDX; ++i) {
			for (int j = 0; j < MAX_IDX; ++j) {
				marked[i][j] |= (bingo_board[i][j] == called_number);
			}
		}

		// check for bingo
		if (is3Bingo() == true) {
			printf("%d\n", num);
			break;
		}
	}
	return 0;
}