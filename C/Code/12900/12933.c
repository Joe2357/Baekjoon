#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_LEN 2500
#define FIRST 'q'
#define SECOND 'u'
#define THIRD 'a'
#define FOURTH 'c'
#define FIFTH 'k'
const int NONE = -1;

char input[MAX_LEN + 1];
int counts[5];
int ret;

#define max(a, b) ((a) > (b) ? (a) : (b))

int main() {
	scanf("%s", input);

	int duck_cnt_in_system = 0;
	for (int i = 0; ret != NONE && input[i] != '\0'; ++i) {
		switch (input[i]) {
			case FIRST: {
				duck_cnt_in_system += 1;
				counts[0] += 1;
				ret = max(ret, duck_cnt_in_system);
				break;
			}
			case SECOND: {
				if (counts[0] == 0) {
					ret = NONE;
				} else {
					counts[0] -= 1;
					counts[1] += 1;
				}
				break;
			}
			case THIRD: {
				if (counts[1] == 0) {
					ret = NONE;
				} else {
					counts[1] -= 1;
					counts[2] += 1;
				}
				break;
			}
			case FOURTH: {
				if (counts[2] == 0) {
					ret = NONE;
				} else {
					counts[2] -= 1;
					counts[3] += 1;
				}
				break;
			}
			case FIFTH: {
				if (counts[3] == 0) {
					ret = NONE;
				} else {
					counts[3] -= 1;
					duck_cnt_in_system -= 1;
				}
				break;
			}
		}
	}

	// final check
	for (int i = 0; i < 5; ++i) {
		if (counts[i] != 0) {
			ret = NONE;
		}
	}

	printf("%d", ret);
	return 0;
}