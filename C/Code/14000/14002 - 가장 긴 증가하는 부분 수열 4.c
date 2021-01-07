#include <stdio.h>

typedef struct Node {
	int len;
	int past;
} ND;

#define M_I 1000
int arr[M_I];
ND dp[M_I];
int rarr[M_I];
int retval;
int point = 0;
int n;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", arr + i);
		dp[i] = (ND) { 1, -1 };
		for (int j = 0; j < i; ++j) {
			if (arr[j] < arr[i] && dp[i].len < dp[j].len + 1)
				dp[i] = (ND) { dp[j].len + 1, j };
		}
		if (dp[point].len < dp[i].len)
			point = i;
	}

	retval = dp[point].len;
	printf("%d\n", retval);
	for (int i = dp[point].len - 1; i >= 0; --i) {
		rarr[i] = arr[point];
		point = dp[point].past;
	}
	for (int i = 0; i < retval; ++i)
		printf("%d ", rarr[i]);

	return 0;
}