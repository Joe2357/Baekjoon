#include <stdio.h>

const int MAX_SUBJECTS = 4;

#define max(a, b) ((a) > (b) ? (a) : (b))

int main() {
	int s = 0, t = 0;
	for (int i = 0; i < MAX_SUBJECTS; ++i) {
		int x;
		scanf("%d", &x);
		s += x;
	}
	for (int i = 0; i < MAX_SUBJECTS; ++i) {
		int x;
		scanf("%d", &x);
		t += x;
	}
	printf("%d", max(s, t));
	return 0;
}