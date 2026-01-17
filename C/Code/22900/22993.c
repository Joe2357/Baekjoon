#include <stdio.h>
#include <stdlib.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef long long ll;

#define MAX_IDX (int)(1e5)
const int PLAYER = 0;

ll atk[MAX_IDX];
int n;

int asc(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &atk[i]);
	}
	qsort(atk + 1, n - 1, sizeof(ll), asc);

	ll sum_atk = atk[PLAYER];
	bool ret = true;
	for (int i = PLAYER + 1; i < n; ++i) {
		if (sum_atk <= atk[i]) {
			ret = false;
			break;
		}
		sum_atk += atk[i];
	}

	printf("%s", ret == true ? "Yes" : "No");
	return 0;
}