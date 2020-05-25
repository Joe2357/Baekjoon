#include <stdio.h>

int main(x, y, w, h) {
	scanf("%d %d %d %d", &x, &y, &w, &h);
	int temp = ( ( x ) >= ( w - x ) ) ? w - x : x;		// search minimun value
	temp = ( ( temp ) >= ( y ) ) ? y : temp;
	temp = ( ( temp ) >= ( h - y ) ) ? h - y : temp;
	printf("%d", temp);
	return 0;
}