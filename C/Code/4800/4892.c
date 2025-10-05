#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

int main() {
	int testcase = 0;
	while (true) {
		int x;
		scanf("%d", &x);

		if (x == 0) {
			break;
		} else {
			printf("%d. %s %d\n", ++testcase, (x % 2 == 0) ? "even" : "odd", x / 2);
		}
	}
	return 0;
}