#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

const int EARTH = 15;
const int SUN = 28;
const int MOON = 19;

int main() {
	int E, S, M;
	scanf("%d %d %d", &E, &S, &M);

	int year = 1;
	for (int e = 1, s = 1, m = 1; true;) {
		if (e == E && s == S && m == M) {
			break;
		}

		year += 1;
		if (++e > EARTH) {
			e = 1;
		}
		if (++s > SUN) {
			s = 1;
		}
		if (++m > MOON) {
			m = 1;
		}
	}

	printf("%d", year);
	return 0;
}