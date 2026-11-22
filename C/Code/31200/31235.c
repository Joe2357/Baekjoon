#include <stdio.h>

#define MAX_IDX (int)(1e6)

int a[MAX_IDX];
int n;

#define max(a, b) ((a) > (b) ? (a) : (b))

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}

	int ret = 1;
	int max_cur_idx = 0;
	for (int i = 1; i < n; ++i) {
		if (a[i] >= a[max_cur_idx]) {
			ret = max(ret, i - max_cur_idx);
			max_cur_idx = i;
		}
	}
	ret = max(ret, n - max_cur_idx);

	printf("%d", ret);
	return 0;
}