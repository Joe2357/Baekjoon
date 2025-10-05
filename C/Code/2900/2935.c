#include <stdio.h>
#include <string.h>

int main() {
	char a[101], b[101], op;
	scanf("%s %c %s", a, &op, b);
	int a0 = strlen(a) - 1, b0 = strlen(b) - 1; // count '0'
	if (b0 > a0) {								// a must be bigger than b
		int temp = a0;
		a0 = b0, b0 = temp;
	}
	if (op == '+') {	// if addition
		if (a0 == b0) { // if same
			printf("2");
			for (int i = 0; i < a0; i++)
				printf("0");
			return 0;
		}
		printf("1"); // if not same
		for (int i = 0; i < a0 - b0 - 1; i++)
			printf("0");
		printf("1");
		for (int i = 0; i < b0; i++)
			printf("0");
		return 0;
	} else if (op == '*') { // if multiple
		printf("1");
		for (int i = 0; i < a0 + b0; i++)
			printf("0");
		return 0;
	}
}