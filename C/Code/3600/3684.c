#include <stdbool.h>
#include <stdio.h>

#define MAX_IDX 100
const int MAX_VALUE = 10000;
const int MOD = 10001;

int arr[MAX_IDX];
int t;

bool check(int a, int b) {
	for (int i = 0; i < t - 1; ++i) {
		int x = arr[i];

		if (arr[i + 1] != ((a * ((a * x + b) % MOD)) + b) % MOD) {
			return false;
		}
	}
	return true;
}

void print_result(int a, int b) {
	for (int i = 0; i < t; ++i) {
		printf("%d\n", (arr[i] * a + b) % MOD);
	}
	return;
}

int main() {
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		scanf("%d", &arr[i]);
	}

	for (int a = 0; a <= MAX_VALUE; ++a) {
		for (int b = 0; b <= MAX_VALUE; ++b) {
			if (check(a, b) == true) {
				print_result(a, b);
				return 0;
			}
		}
	}
	return 0;
}