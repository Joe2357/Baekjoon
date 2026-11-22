#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX (int)(1e6 + 1)

int score[MAX_IDX];
int input[MAX_IDX];
bool isExists[MAX_IDX + 1];
int n;

void solve() {
	for (int i = 0; i < n; ++i) {
		int x = input[i];

		for (int j = x * 2; j < MAX_IDX; j += x) {
			if (isExists[j] == true) {
				++score[x], --score[j];
			}
		}
	}
    return;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		input[i] = x;
		isExists[x] = true;
	}

	solve();

	for (int i = 0; i < n; ++i) {
		printf("%d ", score[input[i]]);
	}
	return 0;
}