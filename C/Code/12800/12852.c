#include <stdio.h>

#define MAX_LEN (int)1e6

typedef struct Node {
	int dp;
	int pre;
} ND;

ND arr[MAX_LEN + 1];
int n;

#define min(a, b) (((a) > (b)) ? (b) : (a))
int main() {
	arr[1] = (ND){0, -1};
	arr[2] = (ND){1, 1};
	arr[3] = (ND){1, 1};

	for (int i = 4; i <= MAX_LEN; ++i) {
		arr[i] = (ND){arr[i - 1].dp, i - 1};

		if (i % 2 == 0 && (arr[i].dp > arr[i >> 1].dp)) {
			arr[i] = (ND){arr[i >> 1].dp, i >> 1};
		}
		if (i % 3 == 0 && (arr[i].dp > arr[i / 3].dp)) {
			arr[i] = (ND){arr[i / 3].dp, i / 3};
		}

		++arr[i].dp;
	}

	scanf("%d", &n);
	printf("%d\n", arr[n].dp);
	for (int target = n; n != -1; n = arr[n].pre) {
		printf("%d ", n);
	}

	return 0;
}