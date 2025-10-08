#include <stdio.h>

const int INF = 987654321;
#define LEN 4
#define MAX_IDX (2 * (1 << LEN))
char input[MAX_IDX][LEN + 1];

#define min(a, b) (((a) > (b)) ? (b) : (a))

int dist[MAX_IDX][MAX_IDX];

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%s", input[i % MAX_IDX]);
		}

		if (n > MAX_IDX) {
			printf("0\n");
		} else {
			for (int i = 0; i < n; ++i) {
				for (int j = i + 1; j < n; ++j) {
					int temp = 0;
					for (int a = 0; a < LEN; ++a) {
						if (input[i][a] != input[j][a]) {
							++temp;
						}
					}
					dist[i][j] = temp;
				}
			}

			int retval = INF;
			for (int i = 0; i < n; ++i) {
				for (int j = i + 1; j < n; ++j) {
					for (int k = j + 1; k < n; ++k) {
						retval = min(retval, dist[i][j] + dist[j][k] + dist[i][k]);
					}
				}
			}

			printf("%d\n", retval);
		}
	}

	return 0;
}