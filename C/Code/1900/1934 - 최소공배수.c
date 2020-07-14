#include <stdio.h>

int main(t) {
	for (scanf("%d", &t); t; t--) {	// test case
		int a, b, A = 0, B = 0;
		scanf("%d %d", &a, &b);
		do							// finding LCM : add something to less value
			if (A > B)
				B += b;
			else
				A += a;
		while (A != B);
		printf("%d\n", A);
	}
	return 0;
}