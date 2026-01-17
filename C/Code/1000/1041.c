#include <stdio.h>

typedef long long ll;

const ll INF = 987654321987654321LL;
#define MAX_SIZE_OF_CUBE 6

ll cube_number[MAX_SIZE_OF_CUBE];
ll n;

ll min_for_1_face, min_for_2_face, min_for_3_face;

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

void read_input() {
	scanf("%lld", &n);
	for (int i = 0; i < MAX_SIZE_OF_CUBE; ++i) {
		scanf("%lld", &cube_number[i]);
	}
	return;
}

void init() {
	min_for_1_face = INF;
	for (int i = 0; i < MAX_SIZE_OF_CUBE; ++i) {
		min_for_1_face = min(min_for_1_face, cube_number[i]);
	}

	min_for_2_face = INF;
	for (int i = 0; i < MAX_SIZE_OF_CUBE; ++i) {
		for (int j = i + 1; j < MAX_SIZE_OF_CUBE; ++j) {
			if (i + j != 5) {
				min_for_2_face = min(min_for_2_face, cube_number[i] + cube_number[j]);
			}
		}
	}

	min_for_3_face = INF;
	for (int i = 0; i < MAX_SIZE_OF_CUBE; ++i) {
		for (int j = i + 1; j < MAX_SIZE_OF_CUBE; ++j) {
			for (int k = j + 1; k < MAX_SIZE_OF_CUBE; ++k) {
				if (i + j != 5 && j + k != 5 && k + i != 5) {
					min_for_3_face = min(min_for_3_face, cube_number[i] + cube_number[j] + cube_number[k]);
				}
			}
		}
	}
	return;
}

int main() {
	read_input();
	init();

	long long result = 0LL;
	if (n == 1LL) {
		int temp = 0;
		for (int i = 0; i < MAX_SIZE_OF_CUBE; ++i) {
			result += cube_number[i];
			temp = max(temp, cube_number[i]);
		}
		result -= temp;
	} else {
		result += (min_for_1_face * max(n - 2, 0) * max(n - 2, 0) * 5); // 중간 면
		result += (min_for_1_face * max(n - 2, 0) * 4);					// 아래 모서리
		result += (min_for_2_face * max(n - 2, 0) * 8);					// 옆+위 모서리
		result += ((min_for_2_face + min_for_3_face) * 4);				// 꼭지점
	}

	printf("%lld", result);
	return 0;
}