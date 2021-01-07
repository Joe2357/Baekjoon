#include <stdio.h>

#define MAX_INDEX 16
int n, complete;
int matrix[MAX_INDEX][MAX_INDEX];
int dp[MAX_INDEX][1 << MAX_INDEX];

#define min(a, b) (((a) > (b)) ? (b) : (a))
#define INF 987654321
#define START 0

int TSP(int pos, int visited) {
	// search complete
	if (visited == complete) {
		if (matrix[pos][START] == 0)
			// no way
			return INF;
		else // has way
			return matrix[pos][START];
	}

	// not complete
	if (dp[pos][visited] > 0)
		// already memorized
		return dp[pos][visited];

	// loop dp
	int temp = INF;
	for (int i = 1; i < n; i++)
		// loop all city except start ( 0 )
		if (((visited & (1 << i)) == 0) && matrix[pos][i] != 0)
			temp = min(temp, TSP(i, (visited | (1 << i))) + matrix[pos][i]);

	// save to dp array
	dp[pos][visited] = temp;
	return temp;
}

int main() {

	// init
	scanf("%d", &n);
	complete = (1 << n) - 1;

	// matrix init
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &matrix[i][j]);

	// print result
	printf("%d", TSP(START, 1));
	return 0;
}