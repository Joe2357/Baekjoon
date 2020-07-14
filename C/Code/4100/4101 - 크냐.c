#include <stdio.h>

int main(a, b) {
	// while a != 0
	for (scanf("%d %d", &a, &b); a; scanf("%d %d", &a, &b))
		if (a > b)
			printf("Yes\n");
		else
			printf("No\n");
	return 0;
}