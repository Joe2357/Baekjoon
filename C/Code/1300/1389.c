#include <stdio.h>
#define min(a, b) (a > b) ? b : a
#define INF 999999
#define MAX_INDEX 100

int person[MAX_INDEX][MAX_INDEX];
int result = INF;
int retval;

void init() {
	for (int a = 0; a < MAX_INDEX; a++)
		for (int b = 0; b < MAX_INDEX; b++)
			if (a != b)
				person[a][b] = INF;
	return;
}

int main(n, t) {
	init();
	for (scanf("%d %d", &n, &t); t; t--) {
		int a, b;
		scanf("%d %d", &a, &b);
		person[--a][--b] = 1, person[b][a] = 1;
	}
	// floyd warshall
	for (int i = 0; i < n; i++) // pass through vertax i
		for (int start = 0; start < n; start++)
			for (int end = 0; end < n; end++)
				person[start][end] = min(person[start][end],
										 person[start][i] + person[i][end]);

	// count result
	for (int i = 0; i < n; i++) {
		int temp = 0;
		for (int a = 0; a < n; a++)
			temp += person[i][a];
		if (temp < result)
			result = temp, retval = i + 1;
	}
	printf("%d", retval);
	return 0;
}