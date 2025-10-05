#include <stdio.h>

const int MAX_IDX = 9;
const int NONE = -1;

int main() {
	int max_val = NONE;
	int x, y;
	for (int i = 0; i < MAX_IDX; ++i) {
		for (int j = 0; j < MAX_IDX; ++j) {
			int temp;
			scanf("%d", &temp);

			if (temp > max_val) {
				max_val = temp;
				x = i, y = j;
			}
		}
	}
	printf("%d\n", max_val);
	printf("%d %d", x + 1, y + 1);
	return 0;
}