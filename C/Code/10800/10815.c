#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX (int)(1e7)

bool card[2 * MAX_IDX + 1 + 1];

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		int num;
		scanf("%d", &num);
		card[num + MAX_IDX] = true;
	}
	int m;
	scanf("%d", &m);
	while (m--) {
		int num;
		scanf("%d", &num);
		if (card[num + MAX_IDX] == true) {
			printf("1 ");
		} else {
			printf("0 ");
		}
	}
	return 0;
}