#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_VAL (2 * 500000)
#define DEC 10

bool isBroken[DEC + 1];
int n;

#define abs(x) (((x) < 0) ? (-(x)) : (x))
#define min(a, b) (((a) > (b)) ? (b) : (a))

bool isValidNumber(int x) {
	if (x == 0) {
		return (isBroken[0] == false);
	}

	bool ret = true;
	while (x > 0) {
		ret &= (isBroken[x % 10] == false);
		x /= 10;
	}

	return ret;
}

int getDigit(int x) {
	if (x == 0) {
		return 1;
	}

	int ret = 0;
	while (x > 0) {
		++ret;
		x /= 10;
	}

	return ret;
}

int main() {
	scanf("%d", &n);
	int t;
	scanf("%d", &t);
	while (t--) {
		int a;
		scanf("%d", &a);
		isBroken[a] = true;
	}

	int ret = abs(n - 100);
	for (int i = 0; i <= MAX_VAL; ++i) {
		if (isValidNumber(i)) {
			ret = min(ret, abs(n - i) + getDigit(i));

			if (i >= n) {
				break;
			}
		}
	}

	printf("%d", ret);
	return 0;
}