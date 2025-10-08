#include <stdio.h>

int main(t) {
	for (scanf("%d", &t); t; t--) {
		int arr[100] = {0}, n, m, imp[10] = {0};
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) {
			scanf("%d", arr + i);
			imp[arr[i]]++;
		}
		int result = 0, a = 9, i = 0;
		while (1) {
			while (!imp[a])
				a--;
			if (arr[i] == a) {
				result++, imp[a]--, arr[i] = 0;
				if (m == i)
					break;
			}
			i = (i + 1) % n;
		}
		printf("%d\n", result);
	}
	return 0;
}