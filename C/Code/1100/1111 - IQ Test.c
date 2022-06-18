#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define M 50

int main() {
	int n;
	scanf("%d", &n);
	int arr[M];
	for (int i = 0; i < n; ++i) {
		scanf("%d", arr + i);
	}

	if (n == 1) {
		printf("A");
		return 0;
	}

	int answer;
	bool hasAnswer = false;
	for (int a = -1000; a <= 1000; ++a) {
		int b = arr[1] - (arr[0] * a);
		bool tempAnswer = true;
		for (int i = 1; i < n - 1; ++i) {
			tempAnswer &= (arr[i] * a + b == arr[i + 1]);
		}

		if (tempAnswer) {
			if (hasAnswer) {
				if (answer != (arr[n - 1] * a + b)) {
					printf("A");
					return 0;
				}
			}
			answer = arr[n - 1] * a + b;
			hasAnswer = true;
		}
	}

	if (hasAnswer) {
		printf("%d", answer);
	} else {
		printf("B");
	}
	return 0;
}