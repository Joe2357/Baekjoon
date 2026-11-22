#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX (int)(1e5)
const int USED = 0;

int parent[MAX_IDX + 1];
int gate;

void init() {
	for (int i = 0; i <= gate; ++i) {
		parent[i] = i;
	}
	return;
}

int find(int x) {
	if (parent[x] == x) {
		return x;
	} else {
		return parent[x] = find(parent[x]);
	}
}
void merge(int a, int b) {
	int x = find(a), y = find(b);
	parent[b] = parent[y] = x;
	return;
}

int main() {
	scanf("%d", &gate);
	init();

	int p;
	scanf("%d", &p);
	int cur;
	for (cur = 0; cur < p; ++cur) {
		int g;
		scanf("%d", &g);

		if (find(g) == USED) {
			break;
		} else {
			int available_gate = find(g);
			merge(find(available_gate - 1), available_gate);
		}
	}
	printf("%d", cur);
	return 0;
}