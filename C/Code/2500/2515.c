#include <stdio.h>
#include <stdlib.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX (int)(3e5)

typedef struct Picture {
	int h, c;
} Picture;

Picture picture[MAX_IDX + 1];
int dp[MAX_IDX + 1]; // dp[i] = i번째 그림을 넣었을 때 얻을 수 있는 가격의 총합
int n, s;

int height_asc(const void* a, const void* b) {
	Picture* x = (Picture*)a;
	Picture* y = (Picture*)b;
	if (x->h > y->h) {
		return 1;
	} else if (x->h < y->h) {
		return -1;
	} else {
		return 0;
	}
}

void read_input() {
	scanf("%d %d", &n, &s);
	picture[0] = (Picture){0, 0};
	for (int i = 1; i <= n; ++i) {
		scanf("%d %d", &picture[i].h, &picture[i].c);
	}
	return;
}

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) > (b)) ? (b) : (a))

int main() {
	read_input();
	qsort(picture, (n + 1), sizeof(Picture), height_asc);

	dp[0] = 0;
	int ret = 0;

	int prev_idx = 0, prev_max_value = 0;
	for (int i = 1; i <= n; ++i) {
		for (; prev_idx < i; ++prev_idx) { // 기준점에 들어올 수 있는지 검사
			if (picture[i].h - picture[prev_idx].h < s) {
				break;
			} else {
				prev_max_value = max(dp[prev_idx], prev_max_value);
			}
		}

		dp[i] = picture[i].c + prev_max_value;
		ret = max(ret, dp[i]);
	}

	printf("%d", ret);
	return 0;
}