#include <stdio.h>

int main(fup1, fup2, fdown1, fdown2) {
	scanf("%d %d %d %d", &fup1, &fdown1, &fup2, &fdown2);
	int fdown3 = fdown1 * fdown2, fup3 = fdown1 * fup2 + fdown2 * fup1;
	for (int i = fdown3; i > 1; i--)
		if (!(fup3 % i) && !(fdown3 % i)) {
			fup3 /= i, fdown3 /= i;
			if (fup3 == 1 || fdown3 == 1)
				break;
		}
	printf("%d %d", fup3, fdown3);
	return 0;
}