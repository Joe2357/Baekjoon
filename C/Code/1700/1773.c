#include <stdio.h>

#define MAX_STUDENT 100
int period[MAX_STUDENT];

int main() {
	int n, c;
	scanf("%d %d", &n, &c);
	for (int i = 0; i < n; ++i) {
		scanf("%d", period + i);
	}

	int result = 0;
	for (int i = 1; i <= c; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i % period[j] == 0) {
				result += 1;
				break;
			}
		}
	}
	printf("%d", result);
	return 0;
}