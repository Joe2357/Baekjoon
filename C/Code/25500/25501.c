#include <stdbool.h>
#include <stdio.h>

#define MAX_LEN 1000

char str[MAX_LEN + 1];

void solve() {
	scanf("%s", str);

	bool isPalindrome = true;
	int call_cnt = 0;

	int s, l;
	for (l = 0; str[l] != '\0'; ++l) { // 문자열 길이 확인
	}

	for (s = 0, l -= 1; true; s += 1, l -= 1) {
		call_cnt += 1;
		if (s >= l) {
			break;
		}
		if (str[s] != str[l]) {
			isPalindrome = false;
			break;
		}
	}

	printf("%d %d\n", (isPalindrome == true), call_cnt);
	return;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}