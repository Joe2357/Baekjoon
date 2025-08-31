#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

const int EXIT_CODE = -1;

int main() {
	int n;

	for (scanf("%d", &n); n != EXIT_CODE; scanf("%d", &n)) {
		// 100,000 이하의 완전수는 4개뿐이다.
		switch (n) {
			case 6: {
				printf("6 = 1 + 2 + 3\n");
				break;
			}
			case 28: {
				printf("28 = 1 + 2 + 4 + 7 + 14\n");
				break;
			}
			case 496: {
				printf("496 = 1 + 2 + 4 + 8 + 16 + 31 + 62 + 124 + 248\n");
				break;
			}
			case 8128: {
				printf("8128 = 1 + 2 + 4 + 8 + 16 + 32 + 64 + 127 + 254 + 508 + 1016 + 2032 + 4064\n");
				break;
			}
			default: {
				printf("%d is NOT perfect.\n", n);
			}
		}
	}

	return 0;
}