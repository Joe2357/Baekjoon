#include <stdio.h>
#define max(a, b) (a < b) ? b : a

int dp[101][100001], arr[100][2], n, k;

int knapsack(int position, int capacity) {
	if (position == n)
		// check all items
		return 0;

	int temp = dp[position][capacity]; // current weight

	if (temp != -1)
		// already searched
		return temp;

	if (arr[position][0] <= capacity)
		// can store more, put it
		temp = arr[position][1] + knapsack(position + 1, capacity - arr[position][0]); // put ro bag
	temp = max(knapsack(position + 1, capacity), temp);								   // didn't put to bag

	dp[position][capacity] = temp; // store current value
	return temp;
}

int main() {
	// dp init
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 100001; j++)
			dp[i][j] = -1;

	// init
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &arr[i][0], &arr[i][1]);

	// print result
	printf("%d", knapsack(0, k));
	return 0;
}