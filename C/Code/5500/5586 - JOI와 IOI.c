#include <stdio.h>

int main() {
	char str[10001] = { 0 };
	scanf("%s", str);
	int j = 0, i = 0;
	// while end of string
	for (int a = 0; str[a] * str[a + 1] * str[a + 2]; a++)
		if (str[a + 1] == 'O' && str[a + 2] == 'I')
			if (str[a] == 'J') // JOI
				j++;
			else if (str[a] == 'I') // IOI
				i++;
	printf("%d\n%d", j, i);
	return 0;
}