#include <stdio.h>
#define MAX_INDEX 10

typedef char boolean;
#define True 1
#define False 0

int arr[MAX_INDEX];
int dp[MAX_INDEX];
int input[MAX_INDEX];
int n;
boolean isAnswerFound;

void func(int x) {
	if (x == n)
		return;
	for (int i = 0; i < n; ++i) {
		if (arr[i] == 0) {
			if (i - dp[i] == input[x]) {
				for (int a = i + 1; a < n; ++a)
					++dp[a];
				arr[i] = x + 1;
				func(x + 1);
				break;
			}
		}
	}
	return;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", input + i);
	func(0);
	for (int i = 0; i < n; ++i)
		printf("%d ", arr[i]);
	return 0;
}