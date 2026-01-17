#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;
typedef long long ll;

#define MAX_IDX (int)(1e6)
#define ARRAY_LENGTH 1000

ll array_a[ARRAY_LENGTH], array_b[ARRAY_LENGTH];
int len_a, len_b;

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) > (b)) ? (b) : (a))

void process(ll x, ll* array, int* l) {
	for (*l = 0; x != 1LL; *l += 1) {
		array[*l] = x;

		if (x % 2LL > 0LL) {
			x = x * 3LL + 1LL;
		} else {
			x = (x >> 1LL);
		}
	}
	array[*l] = 1LL;
	return;
}

int main() {
	int s1, s2;
	ll ret;
	while (true) {
		ll a, b;
		scanf("%lld %lld", &a, &b);
		if (a == 0LL && b == 0LL) {
			break;
		} else if (a == b) {
			s1 = s2 = 0;
			ret = a;
		} else {

			process(a, array_a, &len_a);
			process(b, array_b, &len_b);

			int i = 0;
			for (i = 0; true; ++i) {
				if (array_a[len_a - i] != array_b[len_b - i]) {
					break;
				}
			}
			i -= 1;

			s1 = len_a - i, s2 = len_b - i;
			ret = array_a[len_a - i];
		}

		printf("%lld needs %d steps, %lld needs %d steps, they meet at %lld\n", a, s1, b, s2, ret);
	}
	return 0;
}