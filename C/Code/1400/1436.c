#include <stdio.h>

const int TARGET_NUMBER = 666;
const int DIGIT = 10;

int main() {
	int n;
	scanf("%d", &n);

	int current_number;
	for (current_number = TARGET_NUMBER; n > 0; ++current_number) {
		int temp = current_number;
		while (temp >= TARGET_NUMBER) {
			if (temp % (DIGIT * DIGIT * DIGIT) == TARGET_NUMBER) {
				n -= 1;
				break;
			}
			temp /= DIGIT;
		}
	}
	printf("%d", current_number - 1);
	return 0;
}