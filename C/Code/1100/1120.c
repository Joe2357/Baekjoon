#include <stdio.h>

const int INF = 987654321;
#define MAX_LEN 50

#define min(a, b) ((a) < (b) ? (a) : (b))

char A[MAX_LEN + 1];
int lenA;
char B[MAX_LEN + 1];
int lenB;

int main() {
	scanf("%s %s", A, B);
	for (lenA = 0; A[lenA] != '\0'; ++lenA) {
	}
	for (lenB = 0; B[lenB] != '\0'; ++lenB) {
	}

	int ans = INF;
	for (int i = 0; i <= lenB - lenA; ++i) {
		int cnt = 0;
		for (int j = 0; j < lenA; ++j) {
			cnt += (A[j] != B[i + j]);
		}
		ans = min(ans, cnt);
	}
	printf("%d", ans);
	return 0;
}