#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define M 100
#define INF 987654321

int n, k;
int arr[M];
int next[M + 1];
bool on[M + 2];
int result;

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; ++i) {
		scanf("%d", arr + i);
	}

	int i;
	for (i = 0; n > 0; ++i) {
		if (!on[arr[i]]) {
			on[arr[i]] = true;
			--n;
		}
	}
	for (i = n; i < k; ++i) {
		if (!on[arr[i]]) {
			// 가장 나중에 사용하게 될 플러그 찾기
			int temp = 0;
			for (int j = 1; j <= k; ++j) {
				next[j] = INF;
			}
			for (int j = i + 1; j < k; ++j) {
				if (next[arr[j]] == INF) {
					next[arr[j]] = j;
				}
			}
			for (int j = 1; j <= k; ++j) {
				if (on[j] && next[temp] < next[j]) {
					temp = j;
				}
			}
			// -------------------
			on[temp] = false;
			++result;
			on[arr[i]] = true;
		}
	}

	printf("%d", result);
	return 0;
}