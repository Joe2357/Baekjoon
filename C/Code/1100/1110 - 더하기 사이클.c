#include <stdio.h>

int main() {
	int n, trash, cycle = 0;
	scanf("%d", &n);
	trash = n;
	do
		cycle++, trash = trash % 10 * 10 + (trash / 10 + trash) % 10;	// trash1 = cycle of n
	while (trash != n);
	printf("%d", cycle);
	return 0;
}