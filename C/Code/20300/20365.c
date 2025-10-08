#include <stdio.h>

#define MAX_IDX 500000
const int NONE = -1;

char prob[MAX_IDX + 1];
int n;

int main() {
	scanf("%d", &n);
	scanf("%s", prob);

	n -= 1;
	int ret = 0;
	char cur = NONE;

	for (int i = 0; i <= n; ++i) {
		if (prob[i] != cur) {
			cur = prob[i];
			ret += 1;

			while (n >= 0 && prob[n] == cur) {
				--n;
			}
		}
	}

	printf("%d", ret);
	return 0;
}