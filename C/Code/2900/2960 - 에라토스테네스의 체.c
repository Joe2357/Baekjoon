#include <stdio.h>

int main(n, k) {
	int arr[1001] = { 0 };
	scanf("%d %d", &n, &k);
	for (int i = 2; i <= n; i++) {
		if (!arr[i]) { // if prime
			arr[i] = 1;
			k--;
			if (!k) { // if k th number
				printf("%d", i);
				return 0;
			}
			for (int temp = 2 * i; temp <= n; temp += i) {
				if (!arr[temp]) {
					arr[temp] = 1;
					k--;
					if (!k) { // if k th number
						printf("%d", temp);
						return 0;
					}
				}
			}
		}
	}
}