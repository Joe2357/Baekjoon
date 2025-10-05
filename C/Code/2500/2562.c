#include <stdio.h>

#define MAX_IDX 9
const int NONE = -1;

int main() {
	int max_val = NONE;
	int max_idx = 0;

	for (int i = 0; i < MAX_IDX; i++) {
		int temp;
		scanf("%d", &temp);

		if (temp > max_val)
			max_val = temp, max_idx = i;
	}
	printf("%d\n%d", max_val, max_idx + 1);
	return 0;
}