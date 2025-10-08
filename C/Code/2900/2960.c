#include <stdio.h>

int main() {
	int arr[1001] = {0};
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 2; i <= n; i++) {
		if (!arr[i]) {
			arr[i] = 1;
			k--;
			if (!k) {
				printf("%d", i);
				return 0;
			}
			int temp = i * 2;
			while (temp <= n) {
				if (arr[temp]) {
					temp += i;
					continue;
				}
				arr[temp] = 1;
				k--;
				if (!k) {
					printf("%d", temp);
					return 0;
				}
				temp += i;
			}
		}
	}
}