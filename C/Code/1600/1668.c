#include <stdio.h>

#define MAX_TROPHY 50

int trophy[MAX_TROPHY];
int n;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", trophy + i);
	}
	int result, current_height;

	// 왼쪽 방향
	result = 1;
	current_height = trophy[0];
	for (int i = 1; i < n; ++i) {
		if (trophy[i] > current_height) {
			result += 1;
			current_height = trophy[i];
		}
	}
	printf("%d\n", result);

	// 오른쪽 방향
	result = 1;
	current_height = trophy[n - 1];
	for (int i = n - 2; i >= 0; --i) {
		if (trophy[i] > current_height) {
			result += 1;
			current_height = trophy[i];
		}
	}
	printf("%d", result);
	return 0;
}