#include <stdio.h>

#define MAX_IDX 50
const int MAX_VAL = 1000;
const int NONE = -1;

int A[MAX_IDX], n;
int P[MAX_IDX];

void init() {
	for (int i = 0; i < MAX_IDX; ++i) {
		P[i] = NONE;
	}
	return;
}

int get_target_index() {
	int ret = NONE;
	for (int i = 0; i < n; ++i) {
		if (P[i] == NONE) {
			if (ret == NONE || A[i] < A[ret]) {
				ret = i;
			}
		}
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &A[i]);
	}
	init();
	for (int i = 0; i < n; ++i) {
		P[get_target_index()] = i;
	}
	for (int i = 0; i < n; ++i) {
		printf("%d ", P[i]);
	}
	return 0;
}