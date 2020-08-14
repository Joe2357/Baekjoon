#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_COST 10000

using namespace std;

typedef struct App {
	int memory;
	int cost;
} APP;

int n, m;
int result = MAX_COST + 1;
vector<APP> app;
int dp[MAX_COST + 1];

int main() {
	// i/o init
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	// init
	cin >> n >> m;
	app = vector<APP>(n, { 0, 0 });
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		app[i].memory = temp;
	}
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		app[i].cost = temp;
	}

	// memory dp
	for (int i = 0; i < n; i++)
		for (int j = MAX_COST; j >= app[i].cost; j--)
			dp[j] = max(dp[j], dp[j - app[i].cost] + app[i].memory);

	// get result
	for (int i = 0; i <= MAX_COST; i++)
		if (dp[i] >= m) {
			cout << i;
			break;
		}

	return 0;
}