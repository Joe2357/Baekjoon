#include <stdio.h>

#define MAX_IDX 100

int main() {
	int m, seed, x1, x2;
	scanf("%d %d %d %d", &m, &seed, &x1, &x2);

	for (int a = 0; a <= MAX_IDX; ++a) {
		for (int c = 0; c <= MAX_IDX; ++c) {
			int new_x1 = (a * seed + c) % m;
			int new_x2 = (a * new_x1 + c) % m;
			if (new_x1 == x1 && new_x2 == x2) {
				printf("%d %d\n", a, c);
				return 0;
			}
		}
	}
}