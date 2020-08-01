#include <stdio.h>

int main(n, m, r) {
	int arr[1001] = { 0 };
	for (scanf("%d %d", &n, &m); m; m--) {
		int temp;
		scanf("%d", &temp);
		for (int a = temp; a <= n; a += temp)
			arr[a] = 1;
	}
	r = n * (n + 1) / 2;
	for (int a = 0; a <= n; a++)
		r -= a * (!arr[a]);
	printf("%d", r);
	return 0;
}