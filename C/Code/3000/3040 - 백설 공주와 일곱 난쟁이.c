#include <stdio.h>

int main() {
	int arr[9], sum = 0;
	for (int i = 0; i < 9; i++) {
		scanf("%d", arr + i);
		sum += arr[i]; // sum of 9 number
	}
	for (int i = 0; i < 8; i++)
		for (int j = i + 1; j < 9; j++)
			if (sum - arr[i] - arr[j] == 100) {
				for (int k = 0; k < 9; k++)
					if (k != i && k != j)   // if 
						printf("%d\n", arr[k]);
				return 0;
			} //brute force
}