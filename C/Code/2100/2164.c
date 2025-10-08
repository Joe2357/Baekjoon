#include <stdio.h>

int main(n) {
	scanf("%d", &n);
	int target = 1, cur = 1;
	while (target < n)
		cur *= (target != cur), target++, cur += 2;
	printf("%d", cur);
	return 0;
}