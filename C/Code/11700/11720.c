#include <stdio.h>

#define MAX_LEN 100

char input[MAX_LEN + 1];

int main() {
	int n;
	scanf("%d", &n);
	scanf("%s", input);

	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += (input[i] - '0');
	}
	printf("%d\n", sum);
	return 0;
}