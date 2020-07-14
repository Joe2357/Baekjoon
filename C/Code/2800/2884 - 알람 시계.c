#include <stdio.h>

int main(h, m) {
	scanf("%d %d", &h, &m);
	m -= 45;        // subtract 45 min
	if (m < 0)      // if min is less than 0
		h--,        // change 1 hour to 60 min
		m += 60;
	if (h < 0)      // if hour is less than 0
		h += 24;    // change 1 day to 24 hours
	printf("%d %d", h, m);
	return 0;
}