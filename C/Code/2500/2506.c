#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

int main() {
	int point = 0, cont = 0, n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		if (temp == true) {
			point += ++cont;
		} else {
			cont = 0;
		}
	}
	printf("%d", point);
	return 0;
}