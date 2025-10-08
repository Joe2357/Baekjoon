#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

const int TARGET_AGE = 17;
const int TARGET_WEIGHT = 80;
#define MAX_NAME_LENGTH 10

int main() {
	char name[MAX_NAME_LENGTH + 1];
	int age, weight;

	while (true) {
		scanf("%s %d %d", name, &age, &weight);
		if (name[0] == '#') {
			break;
		} else if ((age > TARGET_AGE) || (weight >= TARGET_WEIGHT)) {
			printf("%s Senior\n", name);
		} else {
			printf("%s Junior\n", name);
		}
	}
	return 0;
}