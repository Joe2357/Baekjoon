#include <stdio.h>

#define MAX_LEN 333334
#define OCTAL 8
#define LENGTH_OF_OCTAL 3

char str[MAX_LEN + 1];
char result[MAX_LEN * 3 + 1];
char template[OCTAL][LENGTH_OF_OCTAL + 1] = {
	"000", "001", "010", "011",
	"100", "101", "110", "111"};

int main() {
	scanf("%s", str);
	int current_idx = 0;

	// 첫글자는 미리 핸들링
	switch (str[0]) {
		case '0': {
			printf("0");
			return 0;
		}
		case '1': {
			result[current_idx++] = '1';
			break;
		}
		case '2': {
			result[current_idx++] = '1';
			result[current_idx++] = '0';
			break;
		}
		case '3': {
			result[current_idx++] = '1';
			result[current_idx++] = '1';
			break;
		}
		default: {
			for (int j = 0; j < LENGTH_OF_OCTAL; ++j) {
				result[current_idx++] = template[str[0] - '0'][j];
			}
			break;
		}
	}

    // 나머지 문자들은 변환 과정만 진행
	for (int i = 1; str[i] != '\0'; ++i) {
		for (int j = 0; j < LENGTH_OF_OCTAL; ++j) {
			result[current_idx++] = template[str[i] - '0'][j];
		}
	}
	printf("%s", result);
	return 0;
}