#include <stdio.h>

int main(m, f) {
	while (1) {
		scanf("%d %d", &m, &f);
		if (!(m + f))
			return 0;
		else
			printf("%d\n", m + f);
	}
}