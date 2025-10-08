#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef struct Result {
	int cnt, len, init_pos, dist;
} RS;

#define MAX_LEN 40
const char CLEAR_WATER = '.';

char grid[MAX_LEN + 1];
int l;

bool isEndInput() {
	return (grid[0] == 'E' && grid[1] == 'N' && grid[2] == 'D' && grid[3] == '\0');
}

RS get_result(int i, int d) {
	if (grid[i] != CLEAR_WATER) {
		return (RS){0, i, i, d};
	} else {
		int cnt = 1;
		int len = i;
		for (int x = i + d; x < l; x += d) {
			len = x;
			if (grid[x] != CLEAR_WATER) {
				break;
			} else {
				cnt += 1;
			}
		}
		return (RS){cnt, len, i, d};
	}
}

bool isGreater(RS a, RS b) {
	if (a.cnt > b.cnt) {
		return true;
	} else if (a.cnt < b.cnt) {
		return false;
	}

	if (a.len > b.len) {
		return true;
	} else if (a.len < b.len) {
		return false;
	}

	if (a.init_pos > b.init_pos) {
		return true;
	} else if (a.init_pos < b.init_pos) {
		return false;
	}

	if (a.dist > b.dist) {
		return false;
	} else if (a.dist < b.dist) {
		return true;
	}
}

int main() {
	while (true) {
		scanf("%s", grid);
		if (isEndInput() == true) {
			break;
		}

		for (l = 0; grid[l] != '\0'; ++l) {
		}

		RS ret = (RS){-1, 0, 0, 0};
		for (int i = 0; i < l; ++i) {
			for (int d = 1; d < l; ++d) {
				RS new_result = get_result(i, d);
				// printf("case %d %d : %d %d %d %d\n", i, d, new_result.cnt, new_result.len, new_result.init_pos, new_result.dist);
				if (isGreater(new_result, ret) == true) {
					ret = new_result;
				}
			}
		}

		printf("%d %d\n", ret.init_pos, ret.dist);
	}

	return 0;
}