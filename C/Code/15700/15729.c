#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_SWITCH (int)(1e6)
const int CHAIN_LENGTH = 2;

bool switch_status[MAX_SWITCH + 1];
bool target_status[MAX_SWITCH + 1];
int n;

#define min(a, b) ((a) < (b) ? (a) : (b))

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		target_status[i] = ((x == 1) ? true : false);
	}

	int ret = 0;
	for (int i = 0; i < n; ++i) {
		if (switch_status[i] != target_status[i]) {
			ret += 1;
			for (int j = i; j <= min(i + CHAIN_LENGTH, n - 1); ++j) {
				switch_status[j] = !switch_status[j];
			}
		}
	}
	printf("%d", ret);
	return 0;
}