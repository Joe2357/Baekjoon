#include <stdio.h>

typedef long long ll;
typedef struct Result {
	ll sum;
	int x, y, z;
} RT;

#define INF (ll)(3e9 + 1)
#define MAX_IDX 5000
int arr[MAX_IDX];
int n;
RT ret = (RT){INF, 0, 0, 0};

int cmp(int* a, int* b) {
	return *a > *b;
}

#define abs(x) (((x) < 0) ? (-(x)) : (x))

void solve(ll target, int left, int right) {
	while (left < right) {
		ll sum = target + arr[left] + arr[right];
		if (abs(sum) < ret.sum) {
			ret = (RT){abs(sum), target, arr[left], arr[right]};
		}
		if (ret.sum == 0) {
			return;
		}
		if (sum < 0) {
			++left;
		}
		if (sum > 0) {
			--right;
		}
	}
	return;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", arr + i);
	}
	qsort(arr, n, sizeof(int), cmp);

	for (int i = 0; i < n; ++i) {
		if (ret.sum == 0) {
			break;
		}
		solve((ll)arr[i], i + 1, n - 1);
	}

	printf("%d %d %d", ret.x, ret.y, ret.z);
	return 0;
}