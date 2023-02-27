#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX (200 + 1)
char result[2][4] = {"NO", "YES"};
bool retval;

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		char str[MAX_IDX];
		scanf("%s", str);

		int cur = 0;

		while (true) {
			if (str[cur] == '\0') {	 // case 0
				retval = true;
				break;
			} else if (str[cur] == '0') {	// case 1
				if (str[cur + 1] != '1') {	// case 2
					retval = false;
					break;
				} else {  // case 3
					cur += 2;
					continue;
				}
			} else if (str[cur] == '1') {  // case 4
				int zeroCount = 0;
				++cur;

				while (str[cur] == '0') {
					++cur;
					++zeroCount;
				}
				if (zeroCount < 2) {  // case 5
					retval = false;
					break;
				}

				int oneCount = 0;
				while (str[cur] == '1') {
					++cur;
					++oneCount;
				}
				if (oneCount < 1) {	 // case 6
					retval = false;
					break;
				} else if (oneCount == 1) {	 // case 7
					continue;
				}

				if (str[cur] == '\0') {	 // case 8
					continue;
				} else if (str[cur + 1] == '0') {  // case 10
					--cur;
					continue;
				} else {  // case 9
					continue;
				}
			}
		}

		printf("%s\n", result[retval]);
	}

	return 0;
}