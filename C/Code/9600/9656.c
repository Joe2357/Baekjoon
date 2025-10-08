#include <stdio.h>

#define MAX_IDX 1000
const int CY = 0, SK = 1;

int loser[MAX_IDX + 1];
int n;

void init() {
	loser[1] = SK;
	loser[2] = CY;
	loser[3] = SK;
	for (int i = 4; i <= MAX_IDX; ++i) {
		if (loser[i - 1] == CY || loser[i - 3] == CY) {
			loser[i] = SK;
		} else {
			loser[i] = CY;
		}
	}
	return;
}

int main() {
	scanf("%d", &n);
	init();
	printf("%s", loser[n] == SK ? "CY" : "SK");
	return 0;
}