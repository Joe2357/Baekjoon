#include <stdio.h>
#include <string.h>
#define max(a, b) (a > b) ? a : b

char arr[50][51] = { 0 };
int n, m, k, result = 0;

int main() {
	int off[51] = { 0 }, right[51] = { 0 };

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", arr[i]);
	scanf("%d", &k);
	// count off-lamps
	for (int i = 0; i < n; i++) {
		int temp = 0;
		for (int j = 0; j < m; j++)
			temp += (arr[i][j] == '0');
		off[i] = temp;
	}
	// count same lines
	for (int i = 0; i < n; i++) {
		int temp = 0;
		for (int j = 0; j < n; j++)
			temp += (strcmp(arr[i], arr[j]) == 0);
		right[i] = temp;
	}
	// find the biggest case
	for (int i = 0; i < n; i++)
		if (off[i] <= k && (k - off[i]) % 2 == 0)
			result = max(result, right[i]);
	printf("%d", result);
	return 0;
}