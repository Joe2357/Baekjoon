#include <stdio.h>
#define min(a, b) (((a) < (b)) ? (a) : (b))

int arr[20][20], n, minValue = 9999;

int evil(int *man) {
	// count variable init
	int result[3] = { 0 };

	// get result value
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (man[i] == man[j])
				result[man[i]] += arr[i][j] + arr[j][i];

	// save subtract of two value
	result[2] = result[0] - result[1];
	if (result[2] < 0)
		result[2] *= -1;

	// return result ( subtract of two value )
	return result[2];
}

// brute force backtracking
void back(int *man, int t, int a) {
	if (t == n / 2) { // divide exactly 2 parts
		minValue = min(minValue, evil(man));
		return;
	}
	else if (a == n)
		// out of range
		return;

	// backtrack init
	int tempMan[20];
	for (int i = 0; i < 20; i++)
		tempMan[i] = man[i];

	// backtrack ( choose or not choose )
	tempMan[a] = 1;
	back(tempMan, t + 1, a + 1);
	tempMan[a] = 0;
	back(tempMan, t, a + 1);

	return;
}

int main() {
	// init
	scanf("%d", &n);
	for (int i = 0; i < n * n; i++)
		scanf("%d", &arr[i / n][i % n]);
	int man[20] = { 0 };

	// backtrack
	back(man, 0, 0);

	// print result
	printf("%d", minValue);
	return 0;
}