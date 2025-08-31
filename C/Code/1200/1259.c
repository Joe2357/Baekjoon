#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

const int EXIT_CODE = 0;

void solve(int x) {
	int std = 10; // 현재 자릿수의 최댓값 선정
	int digit = 1;

	// 자릿수 계산
	while (x >= std) {
		std *= 10;
		digit += 1;
	}

	// 자릿수 고려해서 팰린드롬 계산
	while (digit > 1) {
		int last = x % 10;
		int first = x / (std / 10);

		// 팰린드롬이 아님
		if (last != first) {
			printf("no\n");
			return;
		}

		std /= 10, x = x % std; // first 제거
		std /= 10, x /= 10;		// last 제거
		digit -= 2;				// digit 조정
	}
	printf("yes\n");
	return;
}

int main() {
	while (true) {
		int input;
		scanf("%d", &input);

		// 종료 코드
		if (input == EXIT_CODE) {
			break;
		}
		solve(input);
	}
	return 0;
}