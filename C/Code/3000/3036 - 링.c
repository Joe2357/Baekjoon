#include <stdio.h>

int main(n) {
	scanf("%d", &n);
	int first;
	scanf("%d", &first);
	for (n--; n; n--) {
		int down, up = first;
		scanf("%d", &down);
		while (1) {
			int boolean = 0;
			for (int j = 2; j <= up; j++)
				if (!(up % j) && !(down % j))
					up /= j, down /= j, boolean = 1; // while coprime
			if (!boolean)
				break;
		}
		printf("%d/%d\n", up, down);
	}
	return 0;
}