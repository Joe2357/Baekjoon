#include <stdio.h>

#define MAX_ANT 100000

char ants1[MAX_ANT + 1], ants2[MAX_ANT + 1];
char result[2 * MAX_ANT + 1];
int n1, n2, t; // n1, n2의 범위가 주어지지 않음

void read_input() {
	scanf("%d %d", &n1, &n2);
	scanf("%s %s", ants1, ants2);
	scanf("%d", &t);
	return;
}

void solve() {
	// ants1 뒤집기
	for (int i = 0, j = n1 - 1; i < j; ++i, --j) {
		char temp = ants1[i];
		ants1[i] = ants1[j];
		ants1[j] = temp;
	}

	// 결과 배열에 개미 합치기
	// t :: 개미들이 서로 섞이는 시간 (섞인 개미 수)

	int len = 0;
	int used1 = 0, used2 = 0;

	// ants1에서 섞이지 않은 개미 추가
	for (used1 = 0; used1 < n1 - t; ++used1) {
		result[len++] = ants1[used1];
	}

	// ants2에서 ants1를 모두 넘은 개미 추가
	for (; used2 < t - (n1 - used1) && used2 < n2; ++used2) {
		result[len++] = ants2[used2];
	}

	// 섞인 개미 추가 (ants2 + ants1)
	for (int i = 0; i < t; ++i) {
		if (used2 < n2) {
			result[len++] = ants2[used2++];
		}
		if (used1 < n1) {
			result[len++] = ants1[used1++];
		}
	}

	// ants1에서 ants2를 모두 넘은 개미 추가
	for (; used1 < n1; ++used1) {
		result[len++] = ants1[used1];
	}

	// ants2에서 섞이지 않은 개미 추가
	for (; used2 < n2; ++used2) {
		result[len++] = ants2[used2];
	}
	return;
}

int main() {
	read_input();
	solve();
	printf("%s", result);
	return 0;
}