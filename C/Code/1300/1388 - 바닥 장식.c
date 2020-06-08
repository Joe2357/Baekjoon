#include <stdio.h>

int main(n, m) {
	scanf("%d %d", &n, &m);
	int result = 0;
	char greed[101][101] = { 0 };
	for (int i = 0; i < n; i++)
		scanf("%s", greed[i]);						// making greed
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			switch (greed[i][j]) {					// - or |
				case '-':
					result++;
					for (int k = j; k < m; k++)		// DFS
						if (greed[i][k] != '-')
							break;
						else
							greed[i][k] = 'X';
					break;
				case '|':
					result++;
					for (int k = i; k < n; k++)
						if (greed[k][j] != '|')		// DFS
							break;
						else
							greed[k][j] = 'X';
					break;
			}
		}
	}
	printf("%d", result);
	return 0;
}