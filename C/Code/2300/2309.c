#include <stdio.h>

#define MAX_IDX 9
const int TARGET = 100;

int dwarf[MAX_IDX];

int cmp(int* a, int* b) {
	return *a > *b;
}

int main() {
	int sum = 0; // 모든 난쟁이의 키를 미리 계산
	for (int i = 0; i < MAX_IDX; ++i) {
		scanf("%d", &dwarf[i]);
		sum += dwarf[i];
	}

	// 우선 정렬해야한다
	qsort(dwarf, MAX_IDX, sizeof(int), cmp);

	// 9명의 난쟁이들 중 7명만 사용할 예정이다
	// 즉, 2명을 제외하고 합을 100으로 만들면 된다
	for (int i = 0; i < MAX_IDX; ++i) {
		for (int j = i + 1; j < MAX_IDX; ++j) {
			if (sum - dwarf[i] - dwarf[j] == TARGET) { // i와 j 난쟁이를 포함하지 않는다
				for (int k = 0; k < MAX_IDX; ++k) {
					if (k != i && k != j) {
						printf("%d\n", dwarf[k]);
					}
				}
				return 0;
			}
		}
	}

	return 0;
}