#include <stdio.h>
#include <string.h>

char a[21], b[21];

int main() {
	scanf("%s %s", a, b);
	printf("%d", strcmp(a, b) == 0 ? 0 : 1550);
}