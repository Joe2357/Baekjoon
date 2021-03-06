#include <stdio.h>
#define max(a, b) (a > b) ? a : b
#define min(a, b) (a > b) ? b : a

int main(n, m, block) {
	// init
	scanf("%d %d %d", &n, &m, &block);
	int arr[257], down = 257, up = -1, result[2] = { 2147438647, 257 };
	for (int i = 0; i < 257; i++)
		arr[i] = n * m;

	// check all height, init
	for (int i = 0; i < n * m; i++) {
		int temp;
		scanf("%d", &temp);
		up = max(up, temp),
			down = min(down, temp);
		for (int a = temp + 1; a < 257; a++)
			// arr[a] = blocks count of the floor a
			arr[a]--;
	}

	// get time and remained block
	int rest = 0, tempsec = 0;
	for (int i = down; i <= up; i++)
		rest += (n * m - arr[i]);

	tempsec = rest;

	// downing the highest floor because need more block to fill all
	while (block < rest)
		tempsec = tempsec - (n * m - arr[up]) + (2 * arr[up]),
		rest -= (n * m - arr[up]),
		block += arr[up--];

	// will choose go up, or go down
	result[0] = tempsec, result[1] = up;
	for (int i = up; i >= down && rest; i--) {
		rest -= (n * m - arr[i]),
			tempsec = tempsec - (n * m - arr[i]) + (2 * arr[i]);
		if (tempsec < result[0])
			result[0] = tempsec, result[1] = i - 1;
	}

	// print result
	printf("%d %d", result[0], result[1]);
	return 0;
}