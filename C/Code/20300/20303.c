#include <stdio.h>
#include <stdlib.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef long long ll;

#define MAX_IDX (int)(3e4)
#define MAX_PEOPLE 3000

typedef struct Node {
	ll candy;
	int people_cnt;
} Node;

Node group[MAX_IDX + 1]; // 친구 관계를 모두 묶은 그룹
int parent[MAX_IDX + 1]; // 유니온 파인드 부모 노드
int n, m, k;
int group_len;

ll dp[MAX_PEOPLE + 1];

#define max(a, b) ((a) > (b) ? (a) : (b))

int find(int a) {
	if (parent[a] == a) {
		return a;
	}
	return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
	int root_a = find(a);
	int root_b = find(b);

	if (root_a != root_b) {
		// rootA <= rootB 합침
		group[root_a].candy += group[root_b].candy;
		group[root_a].people_cnt += group[root_b].people_cnt;
		parent[root_b] = root_a;

		// b의 parent도 편입
		parent[b] = root_a;
	}
	return;
}

void read_input() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &group[i].candy);
		group[i].people_cnt = 1;
		parent[i] = i;
	}

	while (m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		merge(a, b);
	}

	// None 그룹 제거
	for (int i = 1; i <= n; ++i) {
		if (find(i) == i) {
			group[group_len++] = group[i];
		}
	}
	return;
}

ll solve() {
	for (int i = 0; i < group_len; ++i) {
		for (int j = k - 1; j >= group[i].people_cnt; --j) {
			dp[j] = max(dp[j], dp[j - group[i].people_cnt] + group[i].candy);
		}
	}

	ll result = dp[k - 1];
	for (int i = k - 1; i >= 0; --i) {
		result = max(result, dp[i]);
	}
	return result;
}

int main() {
	read_input();
	printf("%lld\n", solve());
	return 0;
}