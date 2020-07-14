#include <stdio.h>

int main() {
	int date, car = 0;
	scanf("%d", &date);
	for (int i = 0; i < 5; i++) {
		int temp;
		scanf("%d", &temp);
		car += (temp == date);
	}
	printf("%d", car);
	return 0;
}