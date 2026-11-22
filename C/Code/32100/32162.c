#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 167218 + 1
#define MAX_LEN (int)(1e5)

bool use[MAX_IDX];
int ret[MAX_LEN];
int l = 0;

void init() {
	for (int i = 1; l < MAX_LEN; ++i) {
		if (i % 3 == 0 && use[i / 3] == true) {
			continue;
		}
		if (i % 9 == 0 && use[i / 9] == true) {
			continue;
		}
		if (i % 5 == 0 && use[i / 5] == true) {
			continue;
		}
		if (i % 25 == 0 && use[i / 25] == true) {
			continue;
		}

		use[i] = true;
		ret[l++] = i;
	}

	return;
}

int main() {
	init();

	int t, i;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &i);
		printf("%d\n", ret[i - 1]);
	}

	return 0;
}
