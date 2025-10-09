#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef long long ll;

#define MAX_IDX 20

int n;

ll fact(int x) {
	ll ret = 1;
	for (int i = 2; i <= x; ++i) {
		ret *= i;
	}
	return ret;
}

void find_permutation() {
	ll k;
	scanf("%lld", &k);
	k -= 1LL;

	int arr[MAX_IDX];
	bool used[MAX_IDX + 1] = {false};

	for (int i = 1; i <= n; ++i) {
		ll temp = k / fact(n - i);
		k %= fact(n - i);

		int cur = 0;
		int selected = 0;
		for (int j = 1; j <= n; ++j) {
			if (used[j] == false) {
				if (cur == temp) {
					selected = j;
					used[j] = true;
					break;
				}
				++cur;
			}
		}

		arr[i - 1] = selected;
	}

	for (int i = 0; i < n; ++i) {
		printf("%d ", arr[i]);
	}
	return;
}

void search_permutation() {
	bool used[MAX_IDX + 1] = {false};
	ll k = 0LL;

	for (int i = 1; i <= n; ++i) {
		int temp;
		scanf("%d", &temp);

		ll cur = 0LL;
		used[temp] = true;
		for (int j = 1; j < temp; ++j) {
			if (used[j] == false) {
				cur += 1LL;
			}
		}
		k += (cur * fact(n - i));
	}

	printf("%lld", k + 1LL);
	return;
}

int main() {
	int command;
	scanf("%d %d", &n, &command);
	switch (command) {
		case 1: {
			find_permutation();
			break;
		}
		case 2: {
			search_permutation();
			break;
		}
	}
	return 0;
}