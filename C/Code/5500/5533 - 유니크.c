#include <stdio.h>

int main() {
	int n, point[4][200] = { 0 };
	scanf("%d", &n);

	// input
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			scanf("%d", &point[j][i]);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n; j++) {
			// already erased
			if (!point[i][j])
				continue;
			int boolean = 0;
			// Deduplication
			for (int temp = j + 1; temp < n; temp++)
				if (point[i][j] == point[i][temp])
					boolean = 1, point[i][temp] = 0;
			// if overlapped, erase data
			if (boolean)
				point[i][j] = 0;
		}
		// point sum
		for (int j = 0; j < n; j++)
			point[3][j] += point[i][j];
	}
	for (int i = 0; i < n; i++)
		printf("%d\n", point[3][i]);
	return 0;
}