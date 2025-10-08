#include <stdio.h>

#define MAX_VOTE 100

int votes[MAX_VOTE + 1];

int main() {
	int n;
	scanf("%d", &n);

	int current_vote;
	scanf("%d", &current_vote);

	for (int i = 1; i < n; ++i) {
		int v;
		scanf("%d", &v);
		votes[v] += 1;
	}

	int ret = 0;
	for (int i = MAX_VOTE; i >= current_vote;) {
		if (votes[i] == 0) {
			--i;
			continue;
		} else {
			votes[i] -= 1;
			votes[i - 1] += 1;
			current_vote += 1;
			ret += 1;
		}
	}

	printf("%d", ret);
	return 0;
}