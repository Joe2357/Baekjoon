#include <stdbool.h>
#include <stdio.h>

#define MAX_IDX 500

bool grid[MAX_IDX + 1][MAX_IDX + 1]; // grid[i][j] = i가 j보다 등수가 앞선다
int n;

int answer[MAX_IDX];
int degree[MAX_IDX + 1];
int answer_len;
int queue[MAX_IDX];
int front, rear;

void init() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			grid[i][j] = false;
		}
		degree[i] = 0;
	}
	answer_len = 0;
	front = rear = 0;
	return;
}

void read_input() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &answer[i]); // 임시 사용
		for (int j = 0; j < i; ++j) {
			grid[answer[j]][answer[i]] = true;
		}
	}
	int m;
	scanf("%d", &m);
	while (m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		grid[a][b] ^= true;
		grid[b][a] ^= true;
	}
	return;
}

void solve() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			degree[i] += (grid[j][i] == true);
		}
		if (degree[i] == 0) {
			queue[rear++] = i;
		}
	}

	while (front < rear) {
		int cur = queue[front++];
		answer[answer_len++] = cur;
		for (int i = 1; i <= n; ++i) {
			if (grid[cur][i] == true) {
				grid[cur][i] = false;
				degree[i] -= 1;

				if (degree[i] == 0) {
					queue[rear++] = i;
				}
			}
		}
	}
	return;
}

void print_result() {
	// 참고로 일관성이 없는 경우를 제외하고 순위를 정하지 못하는 경우는 없다
	if (answer_len < n) {
		printf("IMPOSSIBLE");
	} else {
		for (int i = 0; i < n; ++i) {
			printf("%d ", answer[i]);
		}
	}
	printf("\n");
	return;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		init();
		read_input();
		solve();
		print_result();
	}
	return 0;
}