#include <stdio.h>
#define MAX_INDEX 1000000

char str[MAX_INDEX + 1], target[37], stack[MAX_INDEX + 1];
int top, target_length;

typedef char boolean;
#define True 1
#define False 0
boolean check() {
	// length check
	if (top < target_length)
		return False;

	// string compare
	for (int i = top - target_length, j = 0; i < top; i++, j++)
		if (stack[i] != target[j]) // something isn't same
			return False;

	// string compare result is true
	return True;
}

int main() {
	// init
	scanf("%s %s", str, target);
	for (target_length = 0; target[target_length]; ++target_length)
		;

	// stack operation
	for (int i = 0; str[i] != '\0'; ++i) {
		stack[top++] = str[i];
		if (check())
			top -= target_length;
	}

	// print result
	if (top != 0) {
		stack[top++] = '\0';
		printf("%s", stack);
	}
	else
		printf("FRULA");
	return 0;
}