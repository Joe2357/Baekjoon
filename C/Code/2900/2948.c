#include <stdio.h>

#define DAYS 7
#define DAY_LEN 10
#define MONTH_LEN 12

char day_of_the_week[DAYS][DAY_LEN] = {
	"Wednesday",
	"Thursday",
	"Friday",
	"Saturday",
	"Sunday",
	"Monday",
	"Tuesday"};
int day_of_month[MONTH_LEN] = {
	0, 31, 28, 31,
	30, 31, 30, 31,
	31, 30, 31, 30};

int main() {
	int d, m;
	scanf("%d %d", &d, &m);
	while (--m) {
		d += day_of_month[m];
	}
	printf("%s", day_of_the_week[d % 7]);
	return 0;
}