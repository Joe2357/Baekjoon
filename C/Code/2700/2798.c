#include <stdio.h>

#define MAX_IDX 100
const int NONE = -1;

int card[MAX_IDX];
int n, m;

#define max(a, b) (((a) > (b)) ? (a) : (b))

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", card + i);
	}

	int ret = NONE;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			for (int k = j + 1; k < n; ++k) {
				int temp = card[i] + card[j] + card[k];
				if (temp <= m) {
					ret = max(ret, temp);
				}
			}
		}
	}

	printf("%d", ret);
	return 0;
}