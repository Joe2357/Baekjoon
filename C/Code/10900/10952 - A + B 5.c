#include <stdio.h>

int main() {
	while (1) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (!(a + b)) // end of input
			break;
		else
			printf("%d\n", a + b);
	}
	return 0;
}