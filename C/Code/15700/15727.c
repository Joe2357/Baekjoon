#include <stdio.h>

int main() {
	int l;
	scanf("%d", &l);
	printf("%d", l / 5 + (l % 5 > 0));
	return 0;
}