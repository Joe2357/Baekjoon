#include <stdio.h>

int main(n) {
	scanf("%d", &n);
	int target = 1, cur = 1;
	while (target < n)
		cur *= (target != cur), target++, cur += 2;
	printf("%d", cur);
	return 0;
}

/*
	1 : 1	+= 2
	2 : 2	if target == cur
			reset to 0
	3 : 2
	4 : 4

	5 : 2
	6 : 4
	7 : 6
	8 : 8
	--
*/