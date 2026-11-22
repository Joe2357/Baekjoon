#include <stdio.h>
#define MAX_INDEX 100
#define MAX_COST 10000

typedef struct App {
	int memory;
	int cost;
} APP;

int n, m;
int result = MAX_COST + 1;
APP app[MAX_INDEX];
int dp[MAX_COST + 1];

int main() {
	// init
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		app[i].memory = temp;
	}
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		app[i].cost = temp;
	}

	// memory dp
	#define max(a, b) (((a) > (b)) ? (a) : (b))
	for (int i = 0; i < n; i++)
		for (int j = MAX_COST; j >= app[i].cost; j--)
			dp[j] = max(dp[j], dp[j - app[i].cost] + app[i].memory);

	// get result
	for (int i = 0; i <= MAX_COST; i++)
		if (dp[i] >= m) {
			printf("%d", i);
			break;
		}

	return 0;
}