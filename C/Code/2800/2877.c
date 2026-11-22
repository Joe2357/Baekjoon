#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_LEN 33

int reminder[MAX_LEN];
char ans[MAX_LEN];

int main() {
	int k;
	scanf("%d", &k);

	// 자릿수 찾기
	int temp = 2, i = 0;
	while ((temp - 2) < k) {
		temp *= 2, ++i;
	}
	k = k - (temp / 2 - 2) - 1;
	temp /= 4;

	while (temp > 0) {
		if (k >= temp) {
			printf("7");
			k -= temp;
		} else {
			printf("4");
		}

		temp /= 2;
	}

	return 0;
}