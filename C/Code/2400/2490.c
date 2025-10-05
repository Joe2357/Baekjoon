#include <stdio.h>

const char template[6] = "DCBAE";
const int TRIAL_CNT = 3;
const int YOOT_CNT = 4;

int main() {

	for (int i = 0; i < TRIAL_CNT; i++) {
		int result = 0;
		for (int j = 0; j < YOOT_CNT; j++) {
			int temp;
			scanf("%d", &temp);
			result += temp;
		}
		printf("%c\n", template[result]);
	}
	return 0;
}