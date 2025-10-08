#include <stdio.h>
#include <string.h>

#define COMMAND_LEN 10
const int EQUAL = 0;
const int EMPTY = 0;
const int ALL = (1 << 21) - 1;

char command[COMMAND_LEN + 1];
int S;

int main() {
	int m;
	scanf("%d", &m);
	while (m--) {
		scanf("%s", command);

		if (strcmp(command, "add") == EQUAL) {
			int x;
			scanf("%d", &x);
			S |= (1 << (x - 1));
		} else if (strcmp(command, "remove") == EQUAL) {
			int x;
			scanf("%d", &x);
			S &= (ALL - (1 << (x - 1)));
		} else if (strcmp(command, "check") == EQUAL) {
			int x;
			scanf("%d", &x);
			printf("%d\n", (S & (1 << (x - 1))) > 0);
		} else if (strcmp(command, "toggle") == EQUAL) {
			int x;
			scanf("%d", &x);
			S ^= (1 << (x - 1));
		} else if (strcmp(command, "all") == EQUAL) {
			S = ALL;
		} else if (strcmp(command, "empty") == EQUAL) {
			S = EMPTY;
		}
	}
	return 0;
}