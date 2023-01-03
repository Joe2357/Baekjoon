#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define LEN 9
int grid[LEN][LEN + 1] = {0};
bool row[LEN][LEN + 2] = {false};
bool column[LEN][LEN + 2] = {false};
bool box[LEN][LEN + 2] = {false};

void print_result() {
	for (int i = 0; i < LEN; ++i) {
		for (int j = 0; j < LEN; ++j) {
			printf("%c", grid[i][j] + '0');
		}
		printf("\n");
	}
	return;
}

bool solve(int a) {
	if (a >= LEN * LEN) {
		print_result();
		return true;
	}

	int i = a / LEN, j = a % LEN;
	if (grid[i][j] == 0) {
		int x = i / 3, y = j / 3;
		for (int z = 1; z <= LEN; ++z) {
			if (row[i][z] == false && column[j][z] == false &&
				box[x * 3 + y][z] == false) {
				row[i][z] = true;
				column[j][z] = true;
				box[x * 3 + y][z] = true;
				grid[i][j] = z;

				if (solve(a + 1)) {
					return true;
				}

				row[i][z] = false;
				column[j][z] = false;
				box[x * 3 + y][z] = false;
				grid[i][j] = 0;
			}
		}
		return false;
	} else {
		return solve(a + 1);
	}
}

int main() {
	for (int i = 0; i < LEN; ++i) {
		char input[LEN + 1];
		scanf("%s", input);
		for (int j = 0; j < LEN; ++j) {
			int a = input[j] - '0';
			if (a > 0) {
				grid[i][j] = a;
				row[i][a] = true;
				column[j][a] = true;

				int x = i / 3, y = j / 3;
				box[x * 3 + y][a] = true;
			}
		}
	}

	solve(0);
	return 0;
}