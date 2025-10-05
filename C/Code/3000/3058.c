#include <stdio.h>
#define min(a, b) (a > b) ? b : a

int main(t) {
	for (scanf("%d", &t); t; t--) {
		int result = 0, m = 101;
		for (int i = 7; i; i--) {
			int a;
			scanf("%d", &a);
			if (!(a % 2))
				result += a,
					m = min(m, a);
		}
		printf("%d %d\n", result, m);
	}
	return 0;
}