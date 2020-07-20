#include <stdio.h>
#include <string.h>

// 32-bit, can store 32 number
int S;

int main(m) {
	// loop command
	for (scanf("%d", &m); m; m--) {
		// input command 
		char command[9];
		int x;
		scanf("%s", command);

		// command list
		if (!strcmp(command, "add")) {
			scanf("%d", &x);
			S |= (1 << (x - 1));
		}
		else if (!strcmp(command, "remove")) {
			scanf("%d", &x);
			S &= ((1 << 21) - 1 - (1 << (x - 1)));
		}
		else if (!strcmp(command, "check")) {
			scanf("%d", &x);
			printf("%d\n", (S & (1 << (x - 1))) > 0);
		}
		else if (!strcmp(command, "toggle")) {
			scanf("%d", &x);
			S ^= (1 << (x - 1));
		}
		else if (!strcmp(command, "all"))
			S = (1 << 21) - 1;
		else if (!strcmp(command, "empty"))
			S = 0;
	}
	return 0;
}