#include <stdio.h>

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	int profit = c - b;
	if (profit <= 0) { // 이익이 발생하지 않음
		printf("-1");
	} else {
		int break_point = a / profit;  // 자동 floor 처리
		printf("%d", break_point + 1); // "이익"이 발생하는 지점
	}
	return 0;
}