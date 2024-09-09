#include <stdio.h>

#define MAX_IDX 50

int arr[MAX_IDX];
int n;
int s;

#define min(a, b) (((a) > (b)) ? (b) : (a))

int argmax(int x, int y) {
	int retval = x;
	for (int i = x + 1; i < y; ++i) {
		if (arr[i] > arr[retval]) {
			retval = i;
		}
	}
	return retval;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", arr + i);
	}
	scanf("%d", &s);

	for (int i = 0; i < n; ++i) {
		if (s == 0) {
			break;
		}

		int target = argmax(i, min(i + s + 1, n));
		s -= (target - i);

		for (int j = target - 1; j >= i; --j) {
			int temp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = temp;
		}
	}

	for (int i = 0; i < n; ++i) {
		printf("%d ", arr[i]);
	}
	return 0;
}