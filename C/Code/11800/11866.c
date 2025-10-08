#include <stdio.h>

int main() {
	int trash1 = 0, arr[1001] = {0}, n, k;
	scanf("%d %d", &n, &k);
	printf("<");
	for (int i = 0; i < n; i++) {
		int temp = 0;
		while (temp != k) {
			trash1++;
			if (trash1 > n)
				trash1 -= n;
			if (!arr[trash1])
				temp++;
		}
		arr[trash1] = i + 1;
		if (i + 1 == n)
			printf("%d", trash1);
		else
			printf("%d, ", trash1);
	}
	printf(">");
	return 0;
}