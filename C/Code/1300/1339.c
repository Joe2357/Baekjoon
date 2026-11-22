#include <stdio.h>

typedef long long ll;

#define ALPHABET 26
#define MAX_IDX 10
#define MAX_LEN 8
const int DIGIT = 10;

int n;
char words[MAX_IDX][MAX_LEN + 1];
ll idx[ALPHABET][MAX_LEN + 1];
int priority[ALPHABET];

void priority_init() {
	for (int i = 0; i < ALPHABET; ++i) {
		priority[i] = i;
	}
	return;
}

int cmp(int* a, int* b) {
	int ret = 0;

	for (int i = MAX_LEN; i >= 0; --i) {
		if (idx[*a][i] > idx[*b][i]) {
			ret = -1;
			break;
		} else if (idx[*a][i] < idx[*b][i]) {
			ret = 1;
			break;
		}
	}

	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", words[i]);

		int temp = 0;
		for (int j = MAX_LEN; j >= 0; --j) {
			if (words[i][j] != '\0') {
				int alp = words[i][j] - 'A';
				if (++idx[alp][temp++] == DIGIT) {
					idx[alp][temp] -= DIGIT;
					++idx[alp][temp + 1];
				}
			}
		}
	}
	priority_init();

	qsort(priority, ALPHABET, sizeof(int), cmp);

	ll ans = 0;
	int rep = DIGIT - 1;

	for (int i = 0; i < DIGIT; ++i) {
		int temp = priority[i];
		ll digit = 1;

		for (int j = 0; j < MAX_LEN; ++j) {
			ans += (ll)(idx[temp][j] * (rep - i) * digit);
			digit *= DIGIT;
		}
	}

	printf("%lld", ans);
	return 0;
}