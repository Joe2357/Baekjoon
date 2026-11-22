#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

const int INF = 987654321;
#define MAX_CASE 4
const int CENTER = 0;
const int UP = 1;
const int LEFT = 2;
const int DOWN = 3;
const int RIGHT = 4;

int current[MAX_CASE + 1][MAX_CASE + 1];
int temp[MAX_CASE + 1][MAX_CASE + 1];

#define min(a, b) ((a) < (b) ? (a) : (b))

void init(int arr[][MAX_CASE + 1]) {
	for (int i = CENTER; i <= MAX_CASE; ++i) {
		for (int j = 0; j <= MAX_CASE; ++j) {
			arr[i][j] = INF;
		}
	}
	return;
}

void copy_arr(int from[][MAX_CASE + 1], int to[][MAX_CASE + 1]) {
	for (int i = 0; i <= MAX_CASE; ++i) {
		for (int j = 0; j <= MAX_CASE; ++j) {
			to[i][j] = from[i][j];
		}
	}
	return;
}

int get_need_power(int from, int to) {
	if (from == to) {
		return 1;
	} else if (from == CENTER) {
		return 2;
	} else if (((from + 2) % MAX_CASE) == (to % MAX_CASE)) {
		return 4;
	} else {
		return 3;
	}
}

void print_minimum_value(int arr[][MAX_CASE + 1]) {
	int min_value = arr[CENTER][CENTER];
	for (int i = CENTER; i <= MAX_CASE; ++i) {
		for (int j = 0; j <= MAX_CASE; ++j) {
			min_value = min(min_value, arr[i][j]);
		}
	}
	printf("%d", min_value);
	return;
}

int main() {
	init(current);
	current[CENTER][CENTER] = 0;

	do {
		int x;
		scanf("%d", &x);

		if (x == 0) {
			break;
		} else {
			init(temp);

			// left foot step
			for (int i = CENTER; i <= MAX_CASE; ++i) {
				if (x != i) {
					for (int j = CENTER; j <= MAX_CASE; ++j) {
						temp[x][i] = min(temp[x][i], current[j][i] + get_need_power(j, x));
					}
				}
			}

			// right foot step
			for (int i = CENTER; i <= MAX_CASE; ++i) {
				if (x != i) {
					for (int j = CENTER; j <= MAX_CASE; ++j) {
						temp[i][x] = min(temp[i][x], current[i][j] + get_need_power(j, x));
					}
				}
			}

			copy_arr(temp, current);
		}
	} while (true);
	print_minimum_value(current);
	return 0;
}