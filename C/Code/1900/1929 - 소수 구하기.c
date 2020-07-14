#include <stdio.h>

int arr[1000001] = { 1,1 };	// grid

int main(m, n) {
	for (int i = 2; i <= 1000000; i++)					// finding prime number
		if (!arr[i])									// if prime number
			for (int a = i * 2; a <= 1000000; a += i)	// check else multiple value
				arr[a] = 1;
	for (scanf("%d %d", &m, &n); m <= n; m++)			// m ~ n
		if (!arr[m])									// if prime
			printf("%d\n", m);							// print
	return 0;
}