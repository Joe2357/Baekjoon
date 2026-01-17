#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		unsigned int hex;
		scanf("%x", &hex);
		if (hex >= 0x10 && hex < 0x20) {
			printf(".");
		} else {
			printf("-");
		}
	}
	return 0;
}