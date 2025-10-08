#include <stdio.h>

const int TARGET_MONTH = 2;
const int TARGET_DATE = 18;

int main() {
	int month, date;
	scanf("%d %d", &month, &date);

	if (month < TARGET_MONTH || month == TARGET_MONTH && date < TARGET_DATE) {
		printf("Before");
	} else if (month == TARGET_MONTH && date == TARGET_DATE) {
		printf("Special");
	} else {
		printf("After");
	}
	return 0;
}