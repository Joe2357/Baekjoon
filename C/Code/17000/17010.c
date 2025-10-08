#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		char c;
		scanf("%d %c", &n, &c);
		while (n--) {
			printf("%c", c);
		}
		printf("\n");
	}
	return 0;
}