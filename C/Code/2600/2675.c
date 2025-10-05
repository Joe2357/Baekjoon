#include <stdio.h>

#define MAX_LEN 20

char str[MAX_LEN + 1];
int n;

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		scanf("%d %s", &n, str);
		for (int i = 0; str[i] != '\0'; ++i) {
			for (int j = 0; j < n; ++j) {
				printf("%c", str[i]);
			}
		}
		printf("\n");
	}
	return 0;
}