#include <stdio.h>

int main() {
	int std_year, std_month, std_day, year, month, day, tempYear;
	scanf("%d %d %d %d %d %d", &std_year, &std_month, &std_day, &year, &month, &day);
	year -= std_year, tempYear = year;
	if (month < std_month || month == std_month && day < std_day)
		tempYear--;
	printf("%d\n%d\n%d", tempYear, year + 1, year);
	return 0;
}