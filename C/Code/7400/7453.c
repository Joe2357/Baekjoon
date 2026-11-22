#include <stdio.h>

typedef long long ll;

#define MAX_ARR 4
#define MAX_IDX 4000

int arr[MAX_ARR][MAX_IDX];
int middle_result[MAX_ARR / 2][MAX_IDX * MAX_IDX];
int n;

int asc_cmp(int* a, int* b) { return *a > *b; }
int desc_cmp(int* a, int* b) { return *a < *b; }

void read_input() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < MAX_ARR; ++j) {
			scanf("%d", &arr[j][i]);
		}
	}
	return;
}

void make_middle_result(int x1, int x2, int y) {
	int l = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			middle_result[y][l++] = arr[x1][i] + arr[x2][j];
		}
	}
	return;
}

ll solve() {
	ll result = 0;
	ll l = 0, r = 0;
	while (l < n * n && r < n * n) {
		int c = middle_result[0][l] + middle_result[1][r];

		if (c == 0) {
			ll cnt_l = 1, cnt_r = 1;
			while (l + cnt_l < n * n && middle_result[0][l] == middle_result[0][l + cnt_l]) {
				++cnt_l;
			}
			while (r + cnt_r < n * n && middle_result[1][r] == middle_result[1][r + cnt_r]) {
				++cnt_r;
			}
			result += (cnt_l * cnt_r);
			l += cnt_l, r += cnt_r;
		} else if (c > 0) {
			++r;
		} else {
			++l;
		}
	}

	return result;
}

int main() {
	read_input();
	make_middle_result(0, 1, 0);
	make_middle_result(2, 3, 1);

	qsort(middle_result[0], n * n, sizeof(int), asc_cmp);
	qsort(middle_result[1], n * n, sizeof(int), desc_cmp);

	printf("%lld", solve());
	return 0;
}