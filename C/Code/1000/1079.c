#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 16

int R[MAX_IDX][MAX_IDX];

int n, user;
int ret;

#define max(a, b) (((a) > (b)) ? (a) : (b))

void read_input(int* idx) {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", idx + i);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &R[i][j]);
		}
	}
	scanf("%d", &user);
	return;
}

int get_highest_index(int* idx, bool* eliminated) {
	int ret = 0;
	for (int i = 1; i < n; ++i) {
		if (eliminated[ret] == true) {
			ret = i;
		} else if (eliminated[i] == false && idx[i] > idx[ret]) {
			ret = i;
		}
	}
	return ret;
}

void game(int* idx, bool* eliminated, int day, int user_cnt) {
	if (user_cnt < 2) { // only user left
		ret = max(ret, day);
		return;
	} else if (user_cnt % 2 == 1) {
		int will_eliminate = get_highest_index(idx, eliminated);
		if (will_eliminate == user) {
			ret = max(ret, day);
			return;
		}

		eliminated[will_eliminate] = true;
		--user_cnt;
	}

	// night
	for (int i = 0; i < n; ++i) {

		ret = max(ret, day + 1);

		if (eliminated[i] != true && i != user) {
			// kill one user [backtrack start]
			eliminated[i] = true;
			for (int j = 0; j < n; ++j) {
				idx[j] += R[i][j];
			}

			int will_eliminate = get_highest_index(idx, eliminated);
			if (will_eliminate == user) {
				eliminated[i] = false;
				for (int j = 0; j < n; ++j) {
					idx[j] -= R[i][j];
				}
				continue;
			}
			eliminated[will_eliminate] = true;

			game(idx, eliminated, day + 1, user_cnt - 2);

			eliminated[will_eliminate] = false;
			eliminated[i] = false;
			for (int j = 0; j < n; ++j) {
				idx[j] -= R[i][j];
			}
		}
	}
	ret = max(ret, day);
	return;
}

int main() {
	int idx[MAX_IDX];
	bool eliminated[MAX_IDX + 1] = {false};
	read_input(idx);

	game(idx, eliminated, 0, n);

	printf("%d", ret);
	return 0;
}