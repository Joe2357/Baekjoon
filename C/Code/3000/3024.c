#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 30
const int GAME_WIN_LEN = 3;
const char EMPTY = '.';

char grid[MAX_IDX][MAX_IDX + 1];
int n;

void read_input() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", grid[i]);
	}
	return;
}

void solve() {
	bool isAnswerExists = false;

	// 가로줄
	for (int i = 0; i < n; ++i) {
		if (isAnswerExists == true) {
			break;
		}
		for (int j = 0; j <= n - GAME_WIN_LEN; ++j) {
			if (isAnswerExists == true) {
				break;
			}

			char c = grid[i][j];
			if (c == EMPTY) {
				continue;
			}

			bool answerFound = true;
			for (int k = 1; k < GAME_WIN_LEN; ++k) {
				answerFound &= (grid[i][j + k] == c);
			}
			if (answerFound == true) {
				printf("%c", c);
				isAnswerExists = true;
			}
		}
	}

	// 세로줄
	for (int j = 0; j < n; ++j) {
		if (isAnswerExists == true) {
			break;
		}
		for (int i = 0; i <= n - GAME_WIN_LEN; ++i) {
			if (isAnswerExists == true) {
				break;
			}

			char c = grid[i][j];
			if (c == EMPTY) {
				continue;
			}

			bool answerFound = true;
			for (int k = 1; k < GAME_WIN_LEN; ++k) {
				answerFound &= (grid[i + k][j] == c);
			}
			if (answerFound == true) {
				printf("%c", c);
				isAnswerExists = true;
			}
		}
	}

	// 우하향 대각선줄
	for (int col = 0; col <= n - GAME_WIN_LEN; ++col) {
		if (isAnswerExists == true) {
			break;
		}
		for (int row = 0; row <= n - GAME_WIN_LEN; ++row) {
			if (isAnswerExists == true) {
				break;
			}

			char c = grid[row][col];
			if (c == EMPTY) {
				continue;
			}

			bool answerFound = true;
			for (int k = 1; k < GAME_WIN_LEN; ++k) {
				answerFound &= (grid[row + k][col + k] == c);
			}
			if (answerFound == true) {
				printf("%c", c);
				isAnswerExists = true;
			}
		}
	}

	// 우상향 대각선줄
	for (int col = 0; col <= n - GAME_WIN_LEN; ++col) {
		if (isAnswerExists == true) {
			break;
		}
		for (int row = n - 1; row >= GAME_WIN_LEN; --row) {
			if (isAnswerExists == true) {
				break;
			}

			char c = grid[row - 1][col];
			if (c == EMPTY) {
				continue;
			}

			bool answerFound = true;
			for (int k = 1; k < GAME_WIN_LEN; ++k) {
				answerFound &= (grid[row - 1 - k][col + k] == c);
			}
			if (answerFound == true) {
				printf("%c", c);
				isAnswerExists = true;
			}
		}
	}

	if (isAnswerExists == false) {
		printf("ongoing");
	}
	return;
}

int main() {
	read_input();
	solve();
	return 0;
}