#include <stdio.h>

int main(x, y) {
	int date[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	for (scanf("%d %d", &x, &y); x;)		// sum all date
		y += date[--x];
	y %= 7;									// modulo 7 ( SUN ~ SAT )
	char str[7][4] = { "SUN","MON","TUE","WED","THU","FRI","SAT" };
	printf("%s", str[y]);					// print right answer
	return 0;
}