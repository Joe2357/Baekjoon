#include <stdio.h>

int main(a) {
	for (scanf("%d", &a); a; scanf("%d", &a)) {		// until a == 0
		while (a > 9) {								// a is not a digit number
			int temp = 0;
			while (a)
				temp += a % 10, a /= 10;			// temp = sum of all digits
			a = temp;								// renew a
		}
		printf("%d\n", a);
	}
	return 0;
}