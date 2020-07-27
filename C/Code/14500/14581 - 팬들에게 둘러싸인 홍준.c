#include <stdio.h>

int main() {
	char str[21];
	scanf("%s", str);
	printf(":fan::fan::fan:\n"
		":fan::%s::fan:\n"
		":fan::fan::fan:",
		str);
	return 0;
}