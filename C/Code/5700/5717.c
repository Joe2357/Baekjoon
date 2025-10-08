#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

int main() {
	while (true) {
		int m, f;
		scanf("%d %d", &m, &f);
		if (m == 0 && f == 0) {
			break;
		} else {
			printf("%d\n", m + f);
		}
	}
	return 0;
}