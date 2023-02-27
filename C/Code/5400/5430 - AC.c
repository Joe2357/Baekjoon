#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX (int)(1e5)
int arr[MAX_IDX];
int n;
int f, r;
bool isReversed;

char order[MAX_IDX + 1];
char arrInput[MAX_IDX * 4 + 1001];

void init() {
	f = r = 0;
	isReversed = false;
	return;
}

bool preprocess() {
	int temp = 0;
	for (int i = 1; arrInput[i] != ']'; ++i) {
		if (arrInput[i] == ',') {
			arr[r++] = temp;
			temp = 0;
		} else {
			temp *= 10;
			temp += (arrInput[i] - '0');
		}
	}
	if (r < n) {
		arr[r++] = temp;
	}

	int popCount = 0;
	for (int i = 0; order[i] != '\0'; ++i) {
		if (order[i] == 'D') {
			++popCount;
		}
	}
	return (n < popCount);
}

void read_input() {
	scanf("%s", order);
	scanf("%d", &n);
	scanf("%s", arrInput);
	return;
}

void solve() {
	for (int i = 0; order[i] != '\0'; ++i) {
		switch (order[i]) {
			case 'R': {
				isReversed = !isReversed;
				break;
			}
			case 'D': {
				if (isReversed) {
					--r;
				} else {
					++f;
				}
				break;
			}
		}
	}
	return;
}

void print_result() {
	if (r == f) {
		printf("[]\n");
		return;
	}

	printf("[");
	if (isReversed == true) {
		for (r = r - 1; r > f; --r) {
			printf("%d,", arr[r]);
		}
		printf("%d", arr[f]);
	} else {
		for (; f < r - 1; ++f) {
			printf("%d,", arr[f]);
		}
		printf("%d", arr[f]);
	}
	printf("]\n");
	return;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		init();
		read_input();
		if (preprocess() == false) {
			solve();
			print_result();
		} else {
			printf("error\n");
		}
	}
	return 0;
}