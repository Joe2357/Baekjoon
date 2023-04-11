#include <stdio.h>

typedef struct Node {
	int v;
	int idx;
} ND;

#define MAX_IDX (1000000 + 1)
const int START = 0;
const int END = -1;

int arr[MAX_IDX];

ND LIS[MAX_IDX];
int lis[MAX_IDX];
int pre[MAX_IDX];
int lis_len;
int lis_cur;
int n;

int lower_bound(int x) {
	int s = 0, e = lis_len + 1;
	int mid;

	while (s < e) {
		mid = (s + e) / 2;

		if (LIS[mid].v < x) {
			s = mid + 1;
		} else {
			e = mid;
		}
	}

	return e;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", arr + i);
	}
	lis_len = START;
	lis_cur = START;
	LIS[START] = (ND){arr[START], START};
	pre[START] = END;

	for (int i = 1; i < n; ++i) {
		int x = arr[i];

		if (x > LIS[lis_len].v) {
			pre[i] = LIS[lis_len].idx;
			LIS[++lis_len] = (ND){x, i};
			lis_cur = i;
		} else {
			int t = lower_bound(x);
			if (t > 0) {
				pre[i] = LIS[t - 1].idx;
			} else {
				pre[i] = END;
			}
			LIS[t] = (ND){x, i};
		}
	}

	printf("%d\n", lis_len + 1);
	for (int i = 0; lis_cur > END; ++i) {
		lis[i] = arr[lis_cur];
		lis_cur = pre[lis_cur];
	}

	for (int i = lis_len; i >= 0; --i) {
		printf("%d ", lis[i]);
	}
	return 0;
}