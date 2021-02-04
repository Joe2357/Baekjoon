#include <stdio.h>

typedef char boolean;
#define True 1
#define False 0

#define MAX_INDEX (int)4e6
boolean isNotPrime[MAX_INDEX + 1] = { True, True, False };
int prime[MAX_INDEX], len;

void init() {
	for (int i = 2; i <= MAX_INDEX; ++i) {
		if (!isNotPrime[i]) {
			prime[len++] = i;
			for (int j = i * 2; j <= MAX_INDEX; j += i) {
				isNotPrime[j] = True;
			}
		}
	}
	#define INF 987654321
	prime[len++] = INF;
	return;
}

int main() {
	init();

	int left = -1, right = 0;
	int sum = 2, n;
	int result = 0;
	scanf("%d", &n);

	while (prime[right] <= n) {
		if (sum == n) {
			++result;
			sum -= prime[++left];
			sum += prime[++right];
		}
		else if (sum < n) {
			sum += prime[++right];
		}
		else {
			sum -= prime[++left];
		}
	}

	printf("%d", result);
	return 0;
}