#include <stdio.h>
#include <string.h>

#define MAX_LEN (int)(5e5)
const char list[4] = "KSA";
const int list_len = 3;

char str[MAX_LEN + 1];

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int main() {
	scanf("%s", str);
	int len = strlen(str);

	int start_K = 0, start_S = 0, start_A = 0;

	int current_list_index = 0;
	for (int i = 0; i < len; ++i) {
		if (str[i] == list[current_list_index]) {
			start_K += 1;
			current_list_index = (current_list_index + 1) % list_len;
		}
	}

	current_list_index = 1;
	for (int i = 0; i < len; ++i) {
		if (str[i] == list[current_list_index]) {
			start_S += 1;
			current_list_index = (current_list_index + 1) % list_len;
		}
	}
	start_S = min(len - 1, start_S);

	current_list_index = 2;
	for (int i = 0; i < len; ++i) {
		if (str[i] == list[current_list_index]) {
			start_A += 1;
			current_list_index = (current_list_index + 1) % list_len;
		}
	}
	start_A = min(len - 2, start_A);

	printf("%d", 2 * (len - max(start_K, max(start_S, start_A))));
	return 0;
}