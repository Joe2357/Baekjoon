#include <stdio.h>

void print3(int start_row) {
	printf("1 %d\n", start_row);
	printf("2 %d\n", start_row + 1);
	printf("1 %d\n", start_row + 2);
	printf("2 %d\n", start_row);
	printf("1 %d\n", start_row + 1);
	printf("2 %d\n", start_row + 2);
	return;
}
void print4(int start_row) {
	printf("1 %d\n", start_row);
	printf("2 %d\n", start_row + 1);
	printf("1 %d\n", start_row + 3);
	printf("2 %d\n", start_row + 2);
	printf("1 %d\n", start_row + 1);
	printf("2 %d\n", start_row);
	printf("1 %d\n", start_row + 2);
	printf("2 %d\n", start_row + 3);
	return;
}
void print5(int start_row) {
	printf("1 %d\n", start_row);
	printf("2 %d\n", start_row + 2);
	printf("1 %d\n", start_row + 4);
	printf("2 %d\n", start_row + 3);
	printf("1 %d\n", start_row + 1);
	printf("2 %d\n", start_row);
	printf("1 %d\n", start_row + 2);
	printf("2 %d\n", start_row + 4);
	printf("1 %d\n", start_row + 3);
	printf("2 %d\n", start_row + 1);
	return;
}

int main() {
	int n;
	scanf("%d", &n);

	if (n == 1 || n == 2) {
		printf("NO");
	} else {
		printf("YES\n");

		if (n == 3) {
			print3(1);
		} else if (n == 4) {
			print4(1);
		} else if (n == 5) {
			print5(1);
		} else {
			int remainder_of_3 = n % 3;
			int start_row = 1;

			for (int i = 0; i < n / 3 - remainder_of_3; ++i) {
				print3(start_row);
				start_row += 3;
			}
			for (int i = 0; i < remainder_of_3; ++i) {
				print4(start_row);
				start_row += 4;
			}
		}
	}

	return 0;
}