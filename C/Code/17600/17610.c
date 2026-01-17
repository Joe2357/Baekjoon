#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 13
#define MAX_WEIGHT (int)(2e5)

bool canWeight[MAX_IDX * MAX_WEIGHT + 1];
int weight[MAX_IDX];
int n;

#define abs(x) ((x) < 0 ? -(x) : (x))

void dfs(int left, int right, int idx) {
	if (idx == n) {
		return;
	}

	// 추가 안함
	canWeight[abs(left - right)] = true;
	dfs(left, right, idx + 1);

	// left에 추가
	canWeight[abs((left + weight[idx]) - right)] = true;
	dfs(left + weight[idx], right, idx + 1);

	// right에 추가
	canWeight[abs((left) - (right + weight[idx]))] = true;
	dfs(left, right + weight[idx], idx + 1);

	return;
}

int main() {
	int total_weight = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &weight[i]);
		total_weight += weight[i];
	}

	dfs(0, 0, 0);

	int ret = 0;
	for (int i = 1; i <= total_weight; ++i) {
		ret += (canWeight[i] == false);
	}
	printf("%d", ret);
	return 0;
}