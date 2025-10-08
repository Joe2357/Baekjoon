#include <stdio.h>
#define MAX_INDEX 1000000

int main(n, t) {
	char str[MAX_INDEX + 1];
	int temp, result = 0;
	scanf("%d %d %s", &n, &t, str);
	for (int i = 0; str[i]; i++) {
		if (str[i] == 'I') {
			temp = 0;
			while (str[i + 1] && str[i + 2] && str[i + 1] == 'O' && str[i + 2] == 'I')
				temp++, i += 2;
			if (temp >= n)
				result += (temp - n + 1), i -= 2;
		}
	}
	printf("%d", result);
	return 0;
}