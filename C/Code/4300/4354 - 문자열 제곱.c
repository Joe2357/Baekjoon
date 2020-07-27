#include <stdio.h>
#include <string.h>
#define MAX_INDEX 1000000

int main() {
	// loop testcase
	char str[MAX_INDEX + 1];
	for (scanf("%s", str); str[0] != '.'; scanf("%s", str)) {
		// kmp init
		int prefix[MAX_INDEX] = { 0 }, length = strlen(str);
		for (int i = 0, j = 1; str[j];)
			// modify string pointer
			if (str[i] == str[j])
				prefix[j++] = ++i;
			else if (i > 0)
				i = prefix[i - 1];
			else
				prefix[j++] = 0;

		// move to start position
		int maybe = prefix[length - 1], pre = -1;
		while (maybe > 0)
			pre = maybe, maybe = prefix[maybe] - 1;

		// no prefix
		if (pre == -1) {
			printf("1\n");
			continue;
		}

		char cont = 1;
		// check the smallest substring
		for (int temp = pre; temp < length; temp += pre) {
			if (!prefix[temp] || !prefix[pre] || prefix[temp] % prefix[pre] != 0) {
				cont = 0;
				printf("1\n");
				break;
			}
		}

		// print result
		if (cont)
			printf("%d\n", length / pre);
	}

	return 0;
}