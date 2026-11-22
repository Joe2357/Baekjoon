#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_PEOPLE 300
#define MAX_MARKET 10000

int sales[MAX_MARKET + 1][MAX_PEOPLE + 1];
bool responsible[MAX_PEOPLE + 1][MAX_MARKET + 1 + 1];
int best_salesman[MAX_MARKET + 1];
int best_cnt[MAX_PEOPLE + 1];
int n, m, k;
int ret;

void read_input() {
	scanf("%d %d %d", &n, &m, &k);
	for (int person_id = 1; person_id <= n; ++person_id) {
		for (int j = 0; j < k; ++j) {
			int market_id, sales_amount;
			scanf("%d %d", &market_id, &sales_amount);
			sales[market_id][person_id] = sales_amount;
			responsible[person_id][market_id] = true;
		}
	}
	return;
}

void preprocess() {
	ret = 0;
	for (int market_id = 1; market_id <= m; ++market_id) {
		int max_sales = -1;

		for (int person_id = 1; person_id <= n; ++person_id) {
			if (sales[market_id][person_id] > max_sales) {
				max_sales = sales[market_id][person_id];
				best_salesman[market_id] = person_id;
			}
		}

		int best_salesman_id = best_salesman[market_id];
		best_cnt[best_salesman_id] += (responsible[best_salesman_id][market_id] == true);
	}

	for (int person_id = 1; person_id <= n; ++person_id) {
		ret += (best_cnt[person_id] == k);
	}
	return;
}

void query() {
	int person_id, market_id, new_sales;
	scanf("%d %d %d", &person_id, &market_id, &new_sales);
	int old_sales = sales[market_id][person_id];
	sales[market_id][person_id] += new_sales;

	if (best_salesman[market_id] != person_id) {
		int cur_best_salesman = best_salesman[market_id];

		// 1. 가격 비교
		if (sales[market_id][person_id] > sales[market_id][cur_best_salesman]) {

			// 2. 기존 1등에 대한 처리
			if (responsible[cur_best_salesman][market_id] == true) {
				best_cnt[cur_best_salesman] -= 1;
				if (best_cnt[cur_best_salesman] == k - 1) {
					ret -= 1;
				}
			}

			// 3. 새로운 1등에 대한 처리
			best_salesman[market_id] = person_id;
			if (responsible[person_id][market_id] == true) {
				best_cnt[person_id] += 1;
				if (best_cnt[person_id] == k) {
					ret += 1;
				}
			}
		}
	}

	printf("%d\n", ret);
	return;
}

int main() {
	read_input();
	preprocess();

	int q;
	scanf("%d", &q);
	while (q--) {
		query();
	}
	return 0;
}