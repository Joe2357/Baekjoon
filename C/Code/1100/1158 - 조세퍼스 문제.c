#include <stdio.h>

int main() {
	int trash1 = 0, arr[5001] = { 0 }, n, k;
	scanf("%d %d", &n, &k);
	printf("<");								// print start
	for (int i = 0; i < n; i++) {
		int temp = 0;
		while (temp != k) {						// search next value
			trash1++;
			if (trash1 > n)						// we're at last. goto arr[0]
				trash1 -= n;
			if (!arr[trash1])					// if value was already printed, we have to jump it
				temp++;
		}
		arr[trash1] = i + 1;					// count
		if (i + 1 == n)							// last value
			printf("%d", trash1);
		else
			printf("%d, ", trash1);
	}
	printf(">");
	return 0;
}