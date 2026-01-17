#include <stdio.h>

typedef struct Route {
	int start, end, dist;
} Route;

#define MAX_DISTANCE 10000
#define MAX_ROUTES 12

int dp[MAX_DISTANCE + 1];
int n, d;

Route routes[MAX_ROUTES];

#define min(a, b) ((a) < (b) ? (a) : (b))

void read_input() {
	scanf("%d %d", &n, &d);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d %d", &routes[i].start, &routes[i].end, &routes[i].dist);
	}
	return;
}

int main() {
	read_input();

	for (int i = 1; i <= d; ++i) {
		dp[i] = dp[i - 1] + 1;
		for (int j = 0; j < n; ++j) {
			if (routes[j].end == i) {
				dp[i] = min(dp[i], dp[routes[j].start] + routes[j].dist);
			}
		}
	}

	printf("%d", dp[d]);
	return 0;
}