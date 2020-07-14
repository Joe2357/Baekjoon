#include <stdio.h>

int main() {
	char str[101], ban[10] = "CAMBRIDGE";
	scanf("%s", str);
	for (int i = 0; str[i]; i++) {
		int boolean = 1;        // bool variable
		for (int j = 0; j < 9; j++)
			boolean *= (str[i] != ban[j]);  // if alphabet in ban, bool = False
		if (boolean)
			printf("%c", str[i]);
	}
	return 0;
}