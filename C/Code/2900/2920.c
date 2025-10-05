#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 8

int sound[MAX_IDX];

int main() {
	for (int i = 0; i < MAX_IDX; ++i) {
		scanf("%d", sound + i);
	}

	bool isAscending = true;
	bool isDescending = true;
	for (int i = 1; i < MAX_IDX; ++i) {
		isAscending &= (sound[i] > sound[i - 1]);
		isDescending &= (sound[i] < sound[i - 1]);
	}

	if (isAscending == true) {
		printf("ascending");
	} else if (isDescending == true) {
		printf("descending");
	} else {
		printf("mixed");
	}
	return 0;
}