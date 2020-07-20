#include <stdio.h>

int main() {
	int trash1 = 0, arr[1001] = { 0 }, n, k;
	scanf("%d %d", &n, &k);
	printf("<");
	for (int i = 0; i < n; i++) { // loop all number
		int temp = 0;
		while (temp != k) {
			trash1++;
			if (trash1 > n) // modulor
				trash1 -= n;
			if (!arr[trash1]) // number didn't use yet
				temp++;
		}
		arr[trash1] = i + 1; // add number to queue
		if (i + 1 == n)
			printf("%d", trash1);
		else
			printf("%d, ", trash1);
	}
	printf(">");
	return 0;
}