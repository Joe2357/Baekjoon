#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

bool isLeapYear(int year) {
	return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int main() {
	int year;
	scanf("%d", &year);
	printf("%d", isLeapYear(year));
	return 0;
}