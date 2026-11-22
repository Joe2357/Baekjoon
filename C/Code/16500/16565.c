#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;
typedef long long ll;

#define MAX_CARD 52
#define CARD_TYPE 13
const ll MOD = 10007LL;

ll comb[MAX_CARD + 1][MAX_CARD + 1];
int n;

void init_combinations() {
	for (int i = 0; i <= MAX_CARD; ++i) {
		comb[i][0] = 1; // nC0 = 항상 1
		for (int j = 1; j <= i; ++j) {
			comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD; // 조합공식
		}
	}
	return;
}

int main() {
	scanf("%d", &n);
	if (n < 4) { // 애초에 불가능한 경우
		printf("0");
		return 0;
	}
	init_combinations();

	/* 포카드를 뽑는 경우의 수를 구하기 */
	// 4장 이상이라면, 일단 포카드를 한 종류 뽑을 수 있음
	// 그 다음, 가질 수 있는 카드의 갯수에 따라 다른 경우가 발생함

	// 만약 더 뽑을 수 있는 카드의 갯수 k=4장 미만인 경우, 1종류의 포카드가 정해진 다음, 3장을 랜덤하게 뽑는 경우는 48Ck 가지임
	// 포카드의 종류가 13가지이므로, 이 때의 정답은 13 * 48Ck

	// 만약 8 <= n < 12인 경우, 포카드를 2번 뽑을 수도, 아닐수도 있음 (1번은 뽑아야함)
	// 일단 포카드를 1개 뽑음 -> 남은 카드 4 <= k < 8, 이 때 남은 카드를 뽑는 경우는 48Ck
	// 그 중에서 뽑은 카드들이 또 포카드일 수 있음.
	// 포카드를 1개 뽑는 모든 경우에서, 포카드를 2번 뽑은 경우의 수를 제거해야 함.
	// 그래서 정답은 13 * 48Ck - (13C2 * 44C(k-4))가 될 듯?

	// 일반화하면, 뽑을 수 있는 카드의 갯수를 n이라고 하면,
	// \sum_{i=1}^{n/4} -(-1)^{i} * 13Ci * (52-4*i)C(n-4*i) 가 되지 않을까?
	ll ret = 0LL;

	// i = n장으로 뽑은 포카드의 종류를 대변
	for (int i = 1; i <= n / 4; ++i) {
		// i개의 포카드를 뽑을 경우의 수
		ll term = (comb[CARD_TYPE][i] * comb[MAX_CARD - 4 * i][n - 4 * i]) % MOD;

		// 포함 배제의 원리 :: i가 짝수면 빼기, i가 홀수면 더하기
		if (i % 2 == 1) {
			ret = (ret + term) % MOD;
		} else {
			ret = (ret - term + MOD) % MOD;
		}
	}

	printf("%lld", ret);
	return 0;
}