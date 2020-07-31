#include <stdio.h>

int main(n) {
	char str[14][10] = {
		"sukhwan",
		"baby",
		"sukhwan",
		"tururu",
		"turu",
		"very",
		"cute",
		"tururu",
		"turu",
		"in",
		"bed",
		"tururu",
		"turu",
		"baby",
	};
	int arr[14] = { 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1 };
	scanf("%d", &n);
	int temp = n % 14;
	if (arr[temp])
		printf("%s", str[temp]);
	else {
		int ta = n / 14 + 1 + (temp % 2);
		if (ta < 5) {
			printf("tu");
			for (; ta; ta--)
				printf("ru");
		}
		else
			printf("tu+ru*%d", ta);
	}
}