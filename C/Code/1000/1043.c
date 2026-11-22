#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX (50 + 1)
int truth[MAX_IDX];
bool isTruth[MAX_IDX];
int n, m, truth_len;

int parent[MAX_IDX];
int find(int x) {
	if (x == parent[x]) {
		return x;
	} else {
		return parent[x] = find(parent[x]);
	}
}
void merge(int a, int b) {
	int x = find(a), y = find(b);

	if (x != y) {
		parent[y] = parent[b] = x;
	}
	return;
}

int party[MAX_IDX][MAX_IDX];

void read_input() {
	for (int i = 0; i < truth_len; ++i) {
		scanf("%d", truth + i);
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d", &party[i][0]);
		for (int j = 1; j <= party[i][0]; ++j) {
			scanf("%d", &party[i][j]);
			merge(party[i][1], party[i][j]);
		}
	}
	return;
}
void disjoint_init() {
	for (int i = 1; i <= n; ++i) {
		parent[i] = i;
	}
	return;
}

bool truthNotExists(int x) {
	bool retval = false;
	for (int i = 1; i <= party[x][0]; ++i) {
		retval |= isTruth[find(party[x][i])];
	}
	return (retval == false);
}

int main() {
	scanf("%d %d %d", &n, &m, &truth_len);
	disjoint_init();
	read_input();

	for (int i = 0; i < truth_len; ++i) {
		isTruth[truth[i]] = isTruth[find(truth[i])] = true;
	}

	int result = 0;
	for (int i = 0; i < m; ++i) {
		result += truthNotExists(i);
	}

	printf("%d", result);
	return 0;
}