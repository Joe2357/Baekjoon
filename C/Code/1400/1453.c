#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 100

bool isOccupied[MAX_IDX + 1 + 1];

int main() {
	int n;
	scanf("%d", &n);

	int result = 0;
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		if (isOccupied[temp] == false) {
			isOccupied[temp] = true;
		} else {
			result += 1;
		}
	}
	printf("%d", result);
	return 0;
}