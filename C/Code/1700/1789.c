#include <math.h>
#include <stdio.h>

int main() {
	unsigned int s, i;
	scanf("%u", &s);
	i = sqrt((double)s * 2);
	while (i * (i + 1) > s * 2) {
		i--;
	}
	printf("%u", i);
	return 0;
}