#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 1000

bool isExists[2 * MAX_IDX + 1 + 1];

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		int num;
		scanf("%d", &num);
		isExists[num + MAX_IDX] = true;
	}
	for (int i = 0; i < 2 * MAX_IDX + 1; i++) {
		if (isExists[i] == true) {
			printf("%d ", i - MAX_IDX);
		}
	}
	return 0;
}