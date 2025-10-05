#include <stdio.h>

#define MAX_VOTER 15

char vote[MAX_VOTER + 1];

int main() {
	int vote_a = 0, vote_b = 0;
	int v;
	scanf("%d", &v);
	scanf("%s", vote);
	for (int i = 0; i < v; ++i) {
		vote_a += (vote[i] == 'A'), vote_b += (vote[i] == 'B');
	}

	if (vote_a > vote_b) {
		printf("A");
	} else if (vote_a < vote_b) {
		printf("B");
	} else {
		printf("Tie");
	}
	return 0;
}