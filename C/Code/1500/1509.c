#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 2500

char str[MAX_IDX + 1];
int len;
bool isPalindrome[MAX_IDX + 1 + 1][MAX_IDX + 1 + 1];
int dp[MAX_IDX + 1 + 1]; // dp[i] = 0번째 글자부터 i-1번째 글자까지의 팰린드롬 분할 최소 개수

#define min(a, b) ((a) < (b) ? (a) : (b))

void init() {
	for (len = 0; str[len] != '\0'; ++len) {
		isPalindrome[len][len] = isPalindrome[len][len + 1] = true;
	}
	return;
}

void make_palindrome_table() {
	for (int size = 2; size <= len; ++size) {
		for (int end = len; end >= size; --end) {
			int start = end - size;
			isPalindrome[start][end] = (str[start] == str[end - 1] && isPalindrome[start + 1][end - 1] == true);
		}
	}
	return;
}

void make_dp_table() {
	for (int end = 0; end <= len; ++end) {
		dp[end] = end;
		for (int start = 0; start <= end; ++start) {
			if (isPalindrome[start][end] == true) {
				dp[end] = min(dp[end], dp[start] + 1);
			}
		}
	}
	return;
}

void print_dp_table() {
	printf("%3c ", ' ');
	for (int i = 0; i < len; ++i) {
		printf("%3c ", str[i]);
	}
	printf("\n");
	for (int i = 0; i <= len; ++i) {
		printf("%3d ", dp[i]);
	}
	printf("\n");
	return;
}

int main() {
	scanf("%s", str);
	init();
	make_palindrome_table();
	make_dp_table();
	// print_dp_table();
	printf("%d", dp[len]);
	return 0;
}