#include <stdio.h>

int main(n) {
	for (scanf("%d", &n); n != -1; scanf("%d", &n)) {
		int arr[100001] = { 0 },
			temp = 1;
		while (!arr[temp]) { // Duplicate protection
			if (!(n % temp))
				arr[temp] = 1, arr[n / temp] = 1;
			temp++;
		}
		int result = 0;
		for (int i = 0; i < n; i++) // sum of divisor
			if (arr[i])
				result += i;
		if (result != n) // if not same
			printf("%d is NOT perfect.\n", n);
		else {
			int boolean = 0;
			printf("%d = ", n);
			for (int i = 0; i < n; i++) // not first number
				if (arr[i] && boolean)
					printf("+ %d ", i);
				else if (arr[i]) // first number
					boolean = 1, printf("%d ", i);
			printf("\n");
		}
	}
}