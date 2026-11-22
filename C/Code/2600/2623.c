#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX (1000 + 1)
bool matrix[MAX_IDX][MAX_IDX] = {false};
int ans[MAX_IDX], ansLen;
int deg[MAX_IDX];
int n;

int main() {
	int m;
	scanf("%d %d", &n, &m);
	while (m--) {
		int input[MAX_IDX];
		int t;
		scanf("%d", &t);
		for (int i = 0; i < t; ++i) {
			scanf("%d", input + i);
			for (int j = 0; j < i; ++j) {
				if (matrix[input[j]][input[i]] == false) {
					matrix[input[j]][input[i]] = true;
					++deg[input[i]];
				}
			}
		}
	}

	// topology sort
	bool visited[MAX_IDX] = {false};
	int queue[MAX_IDX], front = 0, rear = 0;
	for (int i = 1; i <= n; ++i) {
		if (deg[i] == 0) {
			visited[i] = true;
			queue[rear++] = i;
		}
	}
	while (front < rear) {
		int x = queue[front++];
		ans[ansLen++] = x;
		for (int i = 1; i <= n; ++i) {
			if (matrix[x][i] == true) {
				if (visited[i] == true) {  // exit state
					printf("0");
					return 0;
				}

				// erase edge
				if (--deg[i] == 0) {
					visited[i] = true;
					queue[rear++] = i;
				}
			}
		}
	}

	if (ansLen < n) {
		printf("0");
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		printf("%d\n", ans[i]);
	}
	return 0;
}