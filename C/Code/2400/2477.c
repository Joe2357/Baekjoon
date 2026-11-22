#include <stdio.h>

#define MAX_SIDE 6
const int EAST = 1;
const int WEST = 2;
const int SOUTH = 3;
const int NORTH = 4;

typedef struct Side {
	int dir;
	int len;
} Side;

Side s[MAX_SIDE];
int k;

int main() {
	int max_w = 0, max_h = 0;
	int idx_w = 0, idx_h = 0;

	scanf("%d", &k);

	for (int i = 0; i < MAX_SIDE; ++i) {
		scanf("%d %d", &s[i].dir, &s[i].len);

		if (s[i].dir == EAST || s[i].dir == WEST) {
			if (s[i].len > max_w) {
				max_w = s[i].len, idx_w = i;
			}
		} else if (s[i].dir == SOUTH || s[i].dir == NORTH) {
			if (s[i].len > max_h) {
				max_h = s[i].len, idx_h = i;
			}
		}
	}

	int big_area = max_w * max_h;

	int small_w = s[(idx_h + 3) % 6].len;
	int small_h = s[(idx_w + 3) % 6].len;
	int small_area = small_w * small_h;

	// 4. 최종 결과 출력
	int total_area = big_area - small_area;
	printf("%d\n", total_area * k);

	return 0;
}