#include <stdio.h>

const int MAX_SIZE = 8;
const int PIECE = 'F';

int main() {
	int result = 0;
	for (int i = 0; i < MAX_SIZE; i++) {
		char status[MAX_SIZE + 1];
		scanf("%s", status);

		for (int j = 0; j < MAX_SIZE; j++) {
			if ((i + j) % 2 == 0) {				// 흰색칸 조건
				result += (status[j] == PIECE); // 말이 있는지 확인
			}
		}
	}
	printf("%d", result);
	return 0;
}