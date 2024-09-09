#include <stdio.h>

int convert_to_number(char* str) {
	int ret = 0;
	for (int i = 0; str[i] != '\0'; ++i) {
		ret = ret * 10 + (str[i] - '0');
	}
	return ret;
}

int main() {
	char input[10];
	int retval;

	scanf("%s", input);
	if (input[0] >= '0' && input[0] <= '9') {
		retval = convert_to_number(input) + 3;
	} else {
		scanf("%s", input);
		if (input[0] >= '0' && input[0] <= '9') {
			retval = convert_to_number(input) + 2;
		} else {
			scanf("%s", input);
			if (input[0] >= '0' && input[0] <= '9') {
				retval = convert_to_number(input) + 1;
			}
		}
	}

	if (retval % 3 == 0) {
		printf("Fizz");
	}
	if (retval % 5 == 0) {
		printf("Buzz");
	}
	if (retval % 3 != 0 && retval % 5 != 0) {
		printf("%d", retval);
	}

	return 0;
}