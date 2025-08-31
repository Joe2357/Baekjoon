#include <stdio.h>

/*
	메모리 제한이 8 MB
	총 1천만개의 숫자를 모두 저장할 수는 없음
	수의 범위가 1~10000이므로 이쪽으로 기록하는 것이 좋을 것
	- count 정렬
*/

#define MAX_NUMBER 10000

int cnt[MAX_NUMBER + 1];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		cnt[a] += 1;
	}

	for (int i = 1; i <= MAX_NUMBER; ++i) {
		for (int j = 0; j < cnt[i]; ++j) {
			printf("%d\n", i);
		}
	}
	return 0;
}