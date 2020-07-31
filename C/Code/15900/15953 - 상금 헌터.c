#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	for (; t; t--) {
		int result = 0, temp;
		scanf("%d", &temp);
		if (temp && temp <= 21) {
			int arr[10] = { 50, 30, 20, 5, 3, 1 }, i = 1;
			while (temp) {
				if (temp <= i)
					result += arr[i - 1] * 100000, temp = 0;
				else {
					temp -= i;
					if (++i == 7)
						temp = 0;
				}
			}
		}
		scanf("%d", &temp);
		if (temp && temp <= 31) {
			int i = 1;
			while (temp) {
				if (temp <= i)
					result += 5120000 / i, temp = 0;
				else {
					temp -= i, i *= 2;
					if (i == 32)
						temp = 0;
				}
			}
		}
		printf("%d\n", result);
	}
	return 0;
}