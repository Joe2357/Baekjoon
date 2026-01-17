#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 100

int arr[MAX_IDX + 1];
bool is_cycle[MAX_IDX + 1 + 1];
int n;

void read_input() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &arr[i]);
	}
	return;
}

int solve(int start) {
	bool visited[MAX_IDX + 1 + 1] = {false};

	int cnt = 0;
	for (int cur = start; true; cur = arr[cur]) {
		if (visited[cur] == true) {
			if (cur != start) {
				cnt = 0;
			} else {
				for (int i = 1; i <= n; ++i) {
					is_cycle[i] |= visited[i];
				}
			}
			break;
		}
		visited[cur] = true;
		cnt += 1;
	}
	return cnt;
}

int main() {
	read_input();

	int ret = 0;
	for (int i = 1; i <= n; ++i) {
		if (is_cycle[i] == false) {
			ret += solve(i);
		}
	}
	printf("%d\n", ret);
	for (int i = 1; i <= n; ++i) {
		if (is_cycle[i] == true) {
			printf("%d\n", i);
		}
	}
	return 0;
}