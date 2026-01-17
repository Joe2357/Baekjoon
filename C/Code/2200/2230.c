#include <stdio.h>

#define MAX_IDX 100000
const int INF = (int)(2e9 + 1);

int arr[MAX_IDX];
int n;
int ret = INF;
int m;

int ascend(int* a, int* b) { return *a > *b; }
#define min(a, b) (((a) > (b)) ? (b) : (a))

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", arr + i);
	}
	qsort(arr, n, sizeof(int), ascend);

	int left = 0, right = 0;
	while (right < n) {
		if (arr[right] - arr[left] >= m) {
			ret = min(ret, arr[right] - arr[left]);
			++left;
		} else {
			++right;
		}
	}

	printf("%d", ret);
	return 0;
}