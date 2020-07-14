#include <stdio.h>

int main() {
	char str[1001];
	// standard
	scanf("%s", str);
	int r = 0;
	// strlen
	while (str[r])
		r++;
	scanf("%s", str);
	int a = 0;
	// strlen
	while (str[a])
		a++;
	if (r >= a)
		printf("go");
	else
		printf("no");
	return 0;
}