#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 25
#define MAX_VAL 1000
#define START 0
#define NONMATCHED -1

bool isNotPrime[MAX_VAL * 2 + 1];
void primeInit() {
	isNotPrime[0] = isNotPrime[1] = true;
	for (int i = 2; i <= MAX_VAL * 2; ++i) {
		if (isNotPrime[i] == false) {
			for (int j = i * 2; j <= MAX_VAL * 2; j += i) {
				isNotPrime[j] = true;
			}
		}
	}
	return;
}

int arr[2][MAX_IDX * 2];  // odd or even
int len[2];
int n;
bool visit[MAX_IDX];
int matched[MAX_IDX];

int cmp(int* a, int* b) {
	return *a > *b;
}

bool matrix[MAX_IDX][MAX_IDX];

bool dfs(int x) {
	for (int i = 0; i < len[1]; ++i) {
		if (matrix[x][i] == true) {
			if (visit[i] == true) {
				continue;
			}
			visit[i] = true;

			if (matched[i] == NONMATCHED || dfs(matched[i]) == true) {
				matched[i] = x;
				return true;
			}
		}
	}
	return false;
}

int main() {
	primeInit();
	scanf("%d", &n);
	scanf("%d", &arr[0][START]);
	len[0] = 1, len[1] = 0;
	for (int i = 1; i < n; ++i) {
		int a;
		scanf("%d", &a);
		bool temp = (((a + arr[0][START]) % 2) == 1);
		arr[temp][len[temp]++] = a;
	}

	if (len[0] != len[1]) {	 // first exit case
		printf("-1");
		return 0;
	}

	qsort(arr[1], len[1], sizeof(int), cmp);
	for (int i = 1; i < len[0]; ++i) {	// except the first element
		for (int j = 0; j < len[1]; ++j) {
			matrix[i][j] = (isNotPrime[arr[0][i] + arr[1][j]] == false);
		}
	}
	bool isAnswerExists = false;

	// search for all node in arr[1][]
	for (int i = 0; i < len[1]; ++i) {
		if (isNotPrime[arr[0][START] + arr[1][i]] == false) {
			matrix[START][i] = true;
			for (int j = 0; j < len[1]; ++j) {
				matched[j] = NONMATCHED;
			}

			// bipartite matching algorithm
			int matchCount = 0;
			for (int j = 0; j < len[1]; ++j) {
				for (int k = 0; k < len[1]; ++k) {
					visit[k] = false;
				}

				if (dfs(j) == true) {
					++matchCount;
				}
			}

			if (matchCount == len[1]) {
				isAnswerExists = true;
				printf("%d ", arr[1][i]);
			}

			matrix[START][i] = false;
		}
	}

	if (isAnswerExists == false) {
		printf("-1");
	}
	return 0;
}