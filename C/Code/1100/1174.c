#include <stdbool.h>
#include <stdio.h>

typedef long long ll;

#define MAX_IDX (int)(1e6)
const ll DIGIT = 10LL;

ll q[1 << 10]; // 최대 갯수는 적음
int front = 0, rear = 0;

int main() {
	int n;
	scanf("%d", &n);

	if (n == 1) {
		printf("0");
		return 0;
	}
	for (ll i = 1LL; i < DIGIT; ++i) {
		q[rear++] = i;
	}

	int current_idx;
	bool isAnswerExists = false;
	for (current_idx = 2; front < rear; ++current_idx) {
		ll cur = q[front++];
		// printf("current_idx: %d, cur: %lld\n", current_idx, cur);

		if (current_idx == n) {
			printf("%lld", cur);
			isAnswerExists = true;
			break;
		}

		for (ll i = 0LL; i < cur % DIGIT; ++i) {
			q[rear++] = cur * DIGIT + i;
		}
	}

	if (isAnswerExists == false) {
		printf("-1");
	}
	return 0;
}