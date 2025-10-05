#include <stdio.h>

#define MAX_IDX 100

int basket[MAX_IDX + 1];

void init() {
	for (int i = 1; i <= MAX_IDX; ++i) {
		basket[i] = i;
	}
	return;
}

void reverse(int a, int b) {
	for (; a <= b; a += 1, b -= 1) {
		int temp = basket[a];
		basket[a] = basket[b];
		basket[b] = temp;
	}
	return;
}

int main() {
	init();
	int n, m;
	scanf("%d %d", &n, &m);
	while (m--) {
		int i, j;
		scanf("%d %d", &i, &j);
		reverse(i, j);
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d ", basket[i]);
	}
	return 0;
}