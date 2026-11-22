#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 100
const int INF = 987654321;

int a[MAX_IDX], b[MAX_IDX];
int n, m;

int common[MAX_IDX];
int k;

int first_a[MAX_IDX + 1];
int first_b[MAX_IDX + 1];

#define min(a, b) (((a) > (b)) ? (b) : (a))

void init() {
	for (int i = 1; i <= MAX_IDX; ++i) {
		first_a[i] = first_b[i] = INF;
	}
	return;
}

void read_input() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d", b + i);
	}
	return;
}

void renew(int x, int y) {
	for (int i = x; i < n; ++i) {
		int v = a[i];
		first_a[v] = min(first_a[v], i);
	}
	for (int i = y; i < m; ++i) {
		int v = b[i];
		first_b[v] = min(first_b[v], i);
	}
	return;
}

int main() {
	read_input();

	for (int current_a = 0, current_b = 0; current_a < n && current_b < m; ++current_a, ++current_b) {
		init();
		renew(current_a, current_b);

		bool isEnd = true;
		for (int i = MAX_IDX; i > 0; --i) {
			if (first_a[i] < INF && first_b[i] < INF) {
				isEnd = false;
				common[k++] = i;
				current_a = first_a[i], current_b = first_b[i];
				break;
			}
		}

		if (isEnd == true) {
			break;
		}
	}

	printf("%d\n", k);
	for (int i = 0; i < k; ++i) {
		printf("%d ", common[i]);
	}
	return 0;
}