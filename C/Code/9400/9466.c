#include <stdio.h>

#define EXITCODE 0
#define UNVISITED 0
#define HOPEFUL 1
#define HOPELESS 2

#define MAX_IDX (int)(1e5 + 1)
int arr[MAX_IDX];
int visit[MAX_IDX];
int result;
int n;

void init() {
	for (int i = 1; i <= n; ++i) {
		visit[i] = UNVISITED;
	}
	result = 0;
	return;
}

int dfs(int x) {
	switch (visit[x]) {
		case HOPEFUL: {
			visit[x] = HOPELESS;
			return x;
		}
		case UNVISITED: {
			visit[x] = HOPEFUL;
			int retval = dfs(arr[x]);

			visit[x] = HOPELESS;
			if (retval != EXITCODE) {
				if (retval != x) {
					return retval;
				}
			} else {
				++result;
			}
		}
	}
	return EXITCODE;
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		init();
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", arr + i);
		}

		for (int i = 1; i <= n; ++i) {
			if (visit[i] == UNVISITED) {
				dfs(i);
			}
		}
		printf("%d\n", result);
	}
	return 0;
}