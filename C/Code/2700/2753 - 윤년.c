#include <stdio.h>

int main(year) {
	scanf("%d", &year);
	printf("%d", (!(year % 4) && year % 100 || !(year % 400))); // divide by 4, but not 100 / or divide by 400
	return 0;
}