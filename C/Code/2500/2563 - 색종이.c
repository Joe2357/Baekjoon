#include <stdio.h>

int main(t) {
	int arr[101][101] = { 0 }, result = 0;
	for (scanf("%d", &t); t; t--) {					// paper count
		int a, b;
		scanf("%d %d", &a, &b);
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
				if (!arr[i + b][j + a])				// if overlapped
					arr[i + b][j + a]++, result++;	// check, result + 1
	}
	printf("%d", result);
	return 0;
}