#include <stdio.h>

typedef long long ll;

#define MAX_IDX 100
int arr[MAX_IDX];

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int n, m;
		scanf("%d %d", &n, &m);

		ll x = 0, y = 0;
		for (int i = 0; i < m; ++i) {
			int temp;
			scanf("%d", &temp);
			x = x * 10 + temp;
		}
		for (int i = 0; i < m; ++i) {
			int temp;
			scanf("%d", &temp);
			y = y * 10 + temp;
		}

		for (int i = 0; i < n; ++i) {
			scanf("%d", arr + i);
		}

		int ans = 0;
		for (int i = 0; i < n; ++i) {
			ll temp = 0;
			for (int j = 0; j < m; ++j) {
				temp = temp * 10 + arr[(i + j) % n];
			}

			if (x <= temp && temp <= y) {
				++ans;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}