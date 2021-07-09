#include <stdio.h>

typedef char bool;
const bool True = 1;
const bool False = 0;

#define MAX_VAL (int)(8e5 + 1)
#define MAX_IDX 5000

bool pair[MAX_VAL];
int arr[MAX_IDX];
int w, n;

int main() {
	scanf("%d %d", &w, &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", arr + i);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (arr[i] + arr[j] > w) {
				continue;
			} else if (pair[w - arr[i] - arr[j]]) {
				printf("YES");
				return 0;
			}
		}
		for (int j = 0; j < i; ++j) {
			pair[arr[i] + arr[j]] = True;
		}
	}

	printf("NO");
	return 0;
}