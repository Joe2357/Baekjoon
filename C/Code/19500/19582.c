#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef long long ll;
typedef struct Contest {
	ll limit;
	ll prize;
} Contest;

#define MAX_CONTEST (int)(1e5)

Contest contest[MAX_CONTEST];
int n;

#define max(a, b) (((a) > (b)) ? (a) : (b))

void read_input() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%lld %lld", &contest[i].limit, &contest[i].prize);
	}
	return;
}

bool check_valid(int absent_idx) {
	ll sum_prize = 0LL;
	for (int i = 0; i < n; ++i) {
		if (i != absent_idx) {
			if (sum_prize > contest[i].limit) {
				return false;
			}
			sum_prize += contest[i].prize;
		}
	}
	return true;
}

int main() {
	read_input();

	bool ret = true,
		 need_absent_once = false;
	ll max_prize_until_now = 0LL,
	   sum_prize_until_now = 0LL;
	for (int i = 0; i < n; ++i) {
		need_absent_once |= (sum_prize_until_now > contest[i].limit);

		if (need_absent_once == true) {
			if (sum_prize_until_now - max_prize_until_now > contest[i].limit) { // 이번 콘테스트는 절대로 나갈 수 없음
				ret = check_valid(i);
				break;
			}
		}

		sum_prize_until_now += contest[i].prize;
		max_prize_until_now = max(max_prize_until_now, contest[i].prize);
	}

	printf("%s", (ret == true) ? "Kkeo-eok" : "Zzz");
	return 0;
}