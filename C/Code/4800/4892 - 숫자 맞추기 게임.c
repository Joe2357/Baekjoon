#include <stdio.h>

int main() {
	// init
	int a, tc = 0;

	// testcase loop
	for (scanf("%d", &a); a; scanf("%d", &a))
		// print result
		printf("%d. %s %d\n", ++tc, (a % 2) ? "odd" : "even", a / 2);

	return 0;
}