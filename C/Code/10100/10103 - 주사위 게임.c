#include <stdio.h>

int main(t) {
	int a = 100, b = 100; // start point
	for (scanf("%d", &t); t; t--) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		// remove score
		if (t1 > t2)
			b -= t1;
		else if (t1 < t2)
			a -= t2;
	}
	printf("%d\n%d", a, b);
	return 0;
}