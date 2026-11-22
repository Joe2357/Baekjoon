#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX (int)(1e5)
const char POSITIVE = '*', NEGATIVE = '/';

int factor[MAX_IDX + 1];
int n;

#define abs(x) ((x) < 0 ? -(x) : (x))

void factorization(int x, bool isDenominator) {
	if (x == 0) {
		factor[0] += 1;
	} else {
		int std = (isDenominator == true ? -1 : 1);

		for (int i = 2; i * i <= x; ++i) {
			while (x % i == 0) {
				factor[i] += std;
				x /= i;
			}
		}
		factor[x] += std;
	}
	return;
}

int main() {
	scanf("%d", &n);

	int input;
	scanf("%d ", &input);
	factorization(abs(input), false);

	char op;
	for (int i = 1; i < n; ++i) {
		scanf("%c %d ", &op, &input);
		factorization(abs(input), (op == NEGATIVE));
	}

	bool ret = true;
	if (factor[0] == 0) {
		for (int i = 2; i <= MAX_IDX; ++i) {
			ret &= (factor[i] >= 0);
		}
	}
	printf("%s", ret == true ? "mint chocolate" : "toothpaste");
	return 0;
}