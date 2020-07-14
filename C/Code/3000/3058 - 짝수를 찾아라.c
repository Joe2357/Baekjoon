#include <stdio.h>
#define min(a, b) (a > b) ? b : a

int main(t) {
	for (scanf("%d", &t); t; t--) {
		int result = 0, m = 101; // input <= 100
		for (int i = 7; i; i--) { // seven times
			int a;
			scanf("%d", &a);
			if (!(a % 2))
				result += a, m = min(m, a); // in even number
		}
		printf("%d %d\n", result, m);
	}
	return 0;
}