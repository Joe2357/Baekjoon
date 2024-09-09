#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef struct Node {
	int v;
	int cnt;
} ND;

#define MAX_IDX 2000
const int NONE = -1;

bool good[MAX_IDX + 1];
ND arr[MAX_IDX];
int n;

#define max(a, b) (((a) > (b)) ? (a) : (b))
int cmp(ND* a, ND* b) { return a->v > b->v; }

int binary_search(int left, int right, int value) {
	while (left <= right) {
		int mid = (left + right) / 2;
		if (arr[mid].v == value) {
			return mid;
		} else if (arr[mid].v < value) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	return NONE;
}

void array_init() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int temp;
		scanf("%d", &temp);
		arr[i] = (ND){temp, 1};
	}
	qsort(arr, n, sizeof(ND), cmp);

	int overlapped = 0;
	for (int i = 1; i < n; ++i) {
		if (arr[i].v == arr[i - overlapped - 1].v) {
			arr[i - overlapped - 1].cnt += 1;
			++overlapped;
		} else {
			arr[i - overlapped] = (ND){arr[i].v, 1};
		}
	}
	n -= overlapped;
	return;
}

int main() {
	array_init();
	int result = 0;

	for (int a = 0; a < n; ++a) {
		/* 좋은 수가 같은 값을 가진 숫자 2개의 합인 경우 */
		if (arr[a].cnt >= 2) {
			int c = binary_search(0, n, arr[a].v + arr[a].v);

			if (c != NONE && good[c] == false) {
				if ((a == c && arr[a].cnt == 2) == false) {
					good[c] = true;
					result += arr[c].cnt;
				}
			}
		}

		/* 좋은 수가 다른 값을 가진 숫자 2개의 합인 경우 */
		for (int b = a + 1; b < n; ++b) {
			int c = binary_search(0, n, arr[a].v + arr[b].v);

			if (c != NONE && good[c] == false) {
				if ((a == c && arr[c].cnt == 1) == false &&
					(b == c && arr[c].cnt == 1) == false) {
					good[c] = true;
					result += arr[c].cnt;
				}
			}
		}
	}

	printf("%d", result);
	return 0;
}