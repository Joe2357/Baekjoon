#include <stdio.h>

int main() {
	int month, date;
	scanf("%d %d", &month, &date);
	if (month < 2 || month == 2 && date < 18)
		printf("Before");
	else if (month == 2 && date == 18)
		printf("Special");
	else
		printf("After");
	return 0;
}