#include <stdio.h>
#include <string.h>

#define MAX_IDX 100
#define MAX_LEN 10

char history[MAX_IDX][MAX_LEN + 1];
int n;
int target;

int main() {
	scanf("%d", &n);

	char str[MAX_LEN + 1];
	for (int i = 0; i < n; ++i) {
		scanf("%s", history[i]);
		if (history[i][0] == '?') {
			target = i;
		}
	}

	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		scanf("%s", str);
		char first = str[0];
		char second = str[strlen(str) - 1];
		if (target == 0 || history[target - 1][strlen(history[target - 1]) - 1] == first) {
			if (target == n - 1 || history[target + 1][0] == second) {
				int boolean = 0;
				for (int i = 0; i < n; ++i) {
					boolean |= (strcmp(str, history[i]) == 0);
				}
				if (boolean == 0) {
					printf("%s", str);
				}
			}
		}
	}

	return 0;
}