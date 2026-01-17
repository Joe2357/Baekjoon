#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_LEN 50

char str[MAX_LEN + 1];
int n;

int main() {
	scanf("%d", &n);
	scanf("%s", str);

	int ret = 0;
	for (int i = 0; i < n; ++i) {
		ret += (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u');
	}
	printf("%d", ret);
	return 0;
}