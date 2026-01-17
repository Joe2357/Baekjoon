#include <stdio.h>

const int INF = 987654321;
#define MAX_LEN (int)(3e5)
#define ALPHABET 26
const int NONE = -1;

int n, m;
char str[MAX_LEN + 1];
char ret[MAX_LEN + 1];

int alphabet_map[ALPHABET][MAX_LEN];
int alphabet_cnt[ALPHABET];
int used_cnt[ALPHABET];

void read_input() {
	scanf("%d %d", &n, &m);
	scanf("%s", str);
	return;
}

void preprocess() {
	for (int i = 0; str[i] != '\0'; ++i) {
		int ch = str[i] - 'a';
		alphabet_map[ch][alphabet_cnt[ch]++] = i;
	}
	return;
}

int get_minimum_index() {
	int minimum_index = NONE;
	for (int i = 0; i < ALPHABET; ++i) {
		if (alphabet_cnt[i] == used_cnt[i]) {
			continue;
		} else if (alphabet_map[i][used_cnt[i]] < INF) {
			if (minimum_index == NONE || alphabet_map[i][used_cnt[i]] < alphabet_map[minimum_index][used_cnt[minimum_index]]) {
				minimum_index = i;
			}
		}
	}
	return minimum_index;
}

void solve() {
	int current_remove_target = 0;
	for (int i = 0; i < m; ++i) {
		while (used_cnt[current_remove_target] >= alphabet_cnt[current_remove_target]) {
			current_remove_target++;
		}
		alphabet_map[current_remove_target][used_cnt[current_remove_target]++] = INF;
	}

	for (int i = 0; i < n - m; ++i) {
		int target = get_minimum_index();
		ret[i] = target + 'a';
		used_cnt[target]++;
	}
	return;
}

int main() {
	read_input();
	preprocess();
	solve();
	printf("%s", ret);
	return 0;
}