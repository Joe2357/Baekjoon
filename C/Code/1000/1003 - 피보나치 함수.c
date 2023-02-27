#include <stdio.h>

typedef struct Node {
	int zero;
	int one;
} ND;

#define MAX_IDX 41
ND answer[MAX_IDX];

int main() {
	// init
	answer[0] = (ND){1, 0};
	answer[1] = (ND){0, 1};
	for (int i = 2; i < MAX_IDX; ++i) {
		answer[i] = (ND){answer[i - 2].zero + answer[i - 1].zero, answer[i - 2].one + answer[i - 1].one};
	}

	// query
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		printf("%d %d\n", answer[n].zero, answer[n].one);
	}
	return 0;
}