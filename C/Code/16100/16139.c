#include <stdbool.h>
#include <stdio.h>

#define MAX_LEN (int)(2e5)
#define ALPHABET 26

int cumulative_sum[ALPHABET][MAX_LEN + 1 + 1]; // arr[c][i] = 0부터 i-1까지 index 중에서 문자 c를 포함하는 갯수
char str[MAX_LEN + 1];

void init() {
	for (char c = 'a'; c <= 'z'; ++c) {
		for (int i = 0; str[i] != '\0'; ++i) {
			cumulative_sum[c - 'a'][i + 1] = cumulative_sum[c - 'a'][i] + (str[i] == c);
		}
	}
	return;
}

int main() {
	scanf("%s", str);
	init();

	int q;
	scanf("%d\n", &q);
	while (q--) {
		char c;
		int l, r;
		scanf("%c %d %d\n", &c, &l, &r);

		printf("%d\n", cumulative_sum[c - 'a'][r + 1] - cumulative_sum[c - 'a'][l]);
	}
	return 0;
}