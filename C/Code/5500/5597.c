#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_STUDENT 30

bool submit[MAX_STUDENT + 1 + 1];

int main() {
	for (int i = 2; i < MAX_STUDENT; ++i) {
		int x;
		scanf("%d", &x);
		submit[x] = true;
	}
	for (int i = 1; i <= MAX_STUDENT; ++i) {
		if (submit[i] == false) {
			printf("%d\n", i);
		}
	}
	return 0;
}