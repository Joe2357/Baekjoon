#include <stdio.h>

int main(fup1, fup2, fdown1, fdown2) {
	scanf("%d %d %d %d", &fup1, &fdown1, &fup2, &fdown2);				// input 2 fractions
	int fdown3 = fdown1 * fdown2, fup3 = fdown1 * fup2 + fdown2 * fup1;	// fup3 / fdown3 = (fup1 / fdown1) + (fup2 / fdown2)
	for (int i = fdown3; i > 1; i--)									// finding division
		if (!(fup3 % i) && !(fdown3 % i)) {								// if found
			fup3 /= i, fdown3 /= i;										// divide two value
			if (fup3 == 1 || fdown3 == 1)								// if condition true
				break;													// end of loop
		}
	printf("%d %d", fup3, fdown3);
	return 0;
}