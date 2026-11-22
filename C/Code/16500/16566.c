#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX (int)(4e6)

bool has[MAX_IDX + 1 + 1 + 1];
int parent[MAX_IDX + 1 + 1];
int n, m, k;

void read_input() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < m; ++i) {
		int x;
		scanf("%d", &x);
		has[x] = true;
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
	parent[a] = parent[x] = y; // 뒷 그룹에 배정할 수 있도록
	return;
}

// 분리집합 init
void init() {
	parent[n + 1] = n + 1; // 도달할 수 없는 영역

	for (int i = n; i > 0; --i) {
		parent[i] = i;
		if (has[i] == false) { // 없는 카드의 경우 있는 집합으로 이동시켜야 함
			merge(i, i + 1);
		}
	}
	return;
}

int main() {
	read_input();
	init();
	while (k--) {
		int q;
		scanf("%d", &q);

		int v = find(q + 1); // 입력으로 주어진 수보다는 큰 카드를 내야 함
		printf("%d\n", v);
		merge(v, v + 1);
	}
	return 0;
}