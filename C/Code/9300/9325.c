#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int s, n;
		scanf("%d %d", &s, &n);
		while (n--) {
			int q, p;
			scanf("%d %d", &q, &p);
			s += q * p;
		}
		printf("%d\n", s);
	}
	return 0;
}