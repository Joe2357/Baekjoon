#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_LEN 10
const int DIGIT = 10;

bool isDigit(char* str) {
	return (str[0] >= '0' && str[0] <= '9');
}

int convert_to_number(char* str) {
	int ret = 0;
	for (int i = 0; str[i] != '\0'; ++i) {
		ret = ret * DIGIT + (str[i] - '0');
	}
	return ret;
}

int main() {
	char input[MAX_LEN];
	int retval;

	scanf("%s", input);
	if (isDigit(input) == true) { // 첫번째 숫자는 +3을 통해 답을 도출 가능
		retval = convert_to_number(input) + 3;
	} else {
		scanf("%s", input);
		if (isDigit(input) == true) { // 두번째 숫자는 +2를 통해 답을 도출 가능
			retval = convert_to_number(input) + 2;
		} else {
			scanf("%s", input);
			if (isDigit(input) == true) { // 최소 하나의 입력은 숫자임이 보장되어있음
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