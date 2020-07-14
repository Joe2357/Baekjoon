#include <stdio.h>

int main(t, i, j, a, b) {
	scanf("%d", &t);
	for (i = 1; i <= t; i++) {
		b = 1;
		for (j = 1; j < 11; j++) {
			scanf("%d", &a);
			if ((j - 1) % 5 + 1 - a)
				b = 0;
		}
		if (b)
			printf("%d\n", i);
	}
	return 0;
}