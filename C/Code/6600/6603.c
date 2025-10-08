#include <stdio.h>

int arr[12], n;

void back(int* tarr, int a, int t) {
	if (t >= n)
		return;
	else if (a == 6) {
		for (int i = 0; i < 6; i++)
			printf("%d ", tarr[i]);
		printf("\n");
		return;
	}
	int temparr[12];
	for (int i = 0; i < a; i++)
		temparr[i] = tarr[i];
	for (int i = t + 1; i < n; i++) {
		temparr[a] = arr[i];
		back(temparr, a + 1, i);
	}
	return;
}

int main() {
	for (scanf("%d", &n); n; scanf("%d", &n)) {
		for (int i = 0; i < n; i++)
			scanf("%d", arr + i);
		int tarr[12];
		back(tarr, 0, -1);
		printf("\n");
	}
	return 0;
}