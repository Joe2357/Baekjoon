#include <stdio.h>
 
int main() {
	int e = 0, s = 0, m = 0, year = 0, e1, s1, m1;
	scanf("%d %d %d", &e1, &s1, &m1);
	while (e != e1 || s != s1 || m1 != m) {
		year++;										// target++
		e += 1 - 15 * (e >= 15);					// if e is bigger than 14, we have to return e to 0
		s += 1 - 28 * (s >= 28);					// same
		m += 1 - 19 * (m >= 19);					// same
	}
	printf("%d", year);
	return 0;
}