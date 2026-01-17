#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_LEN 10000
const int NONE = -1;
const char SENSED = '1';
const char NOT_SENSED = '0';

int k, l, n;
char data[MAX_LEN + 1];

int ret[MAX_LEN + 1];
int ret_len;

int getStatusSequencePosition(int pos, int sequence_length, char status) {
	int ret = NONE;
	for (int i = pos; i <= n; ++i) {
		bool isSensedSequence = true;
		for (int j = 0; j < sequence_length; ++j) {
			char current_data = (i + j < n) ? data[i + j] : NOT_SENSED;
			if (current_data != status) {
				isSensedSequence = false;
				break;
			}
		}
		if (isSensedSequence == true) {
			ret = i;
			break;
		}
	}
	return ret;
}

int main() {
	scanf("%d %d %d", &k, &l, &n);
	scanf("%s", data);

	for (int i = 0; i < n; ++i) {
		int status_on_position = getStatusSequencePosition(i, k, SENSED);
		if (status_on_position == NONE) {
			break;
		} else {
			int status_off_position = getStatusSequencePosition(status_on_position + k, l, NOT_SENSED);
			ret[ret_len++] = status_off_position + l;
			i = status_off_position + l - 1;
		}
	}

	if (ret_len == 0) {
		printf("NIKAD");
	} else {
		for (int i = 0; i < ret_len; ++i) {
			printf("%d\n", ret[i]);
		}
	}
	return 0;
}