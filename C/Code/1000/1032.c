#include <stdio.h>

#define MAX_IDX 50
#define MAX_LEN 50

char file[MAX_IDX][MAX_LEN + 1];
int n;
char ret[MAX_LEN + 1];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", file[i]);
	}

	for (int i = 0; file[0][i]; ++i) {
		ret[i] = file[0][i];
		for (int j = 0; j < n; ++j) {
			if (ret[i] != file[j][i]) {
				ret[i] = '?';
				break;
			}
		}
	}

	printf("%s", ret);
	return 0;
}