#include <stdio.h>

typedef char boolean;
#define True 1
#define False 0

#define MAX_IDX 500
#define MAX_LEN 6000
#define INF 987654321

typedef struct Line {
	int start;
	int end;
	int weight;
} LN;

LN line[MAX_LEN];
int len;
int n, m;
long long direction[MAX_IDX + 1];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		line[len++] = (LN) { a, b, c };
	}
	for (int i = 2; i <= n; ++i) {
		direction[i] = INF;
	}
	direction[1] = 0;

	boolean isChanged = True;
	for (int i = 0; i < n && isChanged; ++i) {
		isChanged = False;
		for (int j = 0; j < m; ++j) {
			LN l = line[j];
			if (direction[l.start] != INF && direction[l.end] > direction[l.start] + l.weight) {
				isChanged = True;
				direction[l.end] = direction[l.start] + l.weight;
			}
		}
	}

	if (isChanged) {
		printf("-1");
	}
	else {
		for (int i = 2; i <= n; ++i) {
			if (direction[i] == INF)
				printf("-1\n");
			else
				printf("%d\n", direction[i]);
		}
	}
	return 0;
}