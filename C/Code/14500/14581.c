#include <stdio.h>

#define MAX_LEN 20

int main() {
	char str[MAX_LEN + 1];
	scanf("%s", str);
	printf(":fan::fan::fan:\n"
		   ":fan::%s::fan:\n"
		   ":fan::fan::fan:",
		   str);
	return 0;
}