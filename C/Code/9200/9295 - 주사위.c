#include <stdio.h>

int main(t) {
	scanf("%d", &t);
	for (int i = 0; i < t;) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("Case %d: %d\n", ++i, a + b);
	}
	return 0;
}