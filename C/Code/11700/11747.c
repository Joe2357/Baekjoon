#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 1000
#define DIGIT 10

int arr[MAX_IDX];
int n;

int map[DIGIT][MAX_IDX];
int len[DIGIT];

void read_input() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		arr[i] = a;
		map[a][len[a]++] = i;
	}
	return;
}

int getFirstDigit(int x) {
	while (x >= DIGIT) {
		x /= DIGIT;
	}
	return x;
}

bool canFind(int x) {
	int firstDigit = getFirstDigit(x);
	for (int s = 0; s < len[firstDigit]; ++s) {
		int i = map[firstDigit][s];
		int temp = firstDigit;

		for (i += 1; temp < x && i < n; ++i) {
			temp = temp * DIGIT + arr[i];
		}

		if (temp == x) {
			return true;
		}
	}
	return false;
}

int main() {
	read_input();

	for (int i = 0; true; ++i) {
		if (canFind(i) == false) {
			printf("%d", i);
			break;
		}
	}
	return 0;
}