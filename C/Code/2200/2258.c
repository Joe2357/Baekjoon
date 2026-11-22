#include <stdio.h>
#include <stdlib.h>

typedef long long ll;
typedef struct Meat {
	ll weight;
	ll price;
} MEAT;

#define MAX_IDX (int)(1e5)
const ll INF = (1LL << 60);
const ll NONE = -1;

MEAT meat[MAX_IDX];

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int price_asc_weight_desc(const void* a, const void* b) {
	MEAT* x = (MEAT*)a;
	MEAT* y = (MEAT*)b;
	if (x->price > y->price) {
		return 1;
	} else if (x->price < y->price) {
		return -1;
	} else {
		if (x->weight > y->weight) {
			return -1;
		} else if (x->weight < y->weight) {
			return 1;
		} else {
			return 0;
		}
	}
}

int main() {
	int n;
	ll m;
	scanf("%d %lld", &n, &m);

	for (int i = 0; i < n; ++i) {
		ll a, b;
		scanf("%lld %lld", &a, &b);
		meat[i] = (MEAT){a, b};
	}
	qsort(meat, n, sizeof(MEAT), price_asc_weight_desc);

	ll step_price = NONE, previous_sum_weight = 0;
	ll current_sum_price = 0, current_sum_weight = 0;
	ll ans = INF;
	for (int i = 0; i < n; ++i) {
		MEAT current_meat = meat[i];

		// 이전 결과 정리
		if (step_price < current_meat.price) {
			step_price = current_meat.price;
			previous_sum_weight += current_sum_weight;
			current_sum_price = 0, current_sum_weight = 0;
		}

		// 현재 고기를 사는 경우 판단
		if (previous_sum_weight + current_sum_weight + current_meat.weight >= m) {
			ans = min(ans, current_sum_price + current_meat.price);
		}

		// 현재 고기에 대한 정보 추가
		current_sum_weight += current_meat.weight;
		current_sum_price += current_meat.price;
	}

	printf("%lld", ans == INF ? -1 : ans);
	return 0;
}