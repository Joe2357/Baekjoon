#include <stdio.h>

int arr[20], result, n, target;

void back(int index, int sum, int isNotNULL) {
	if (index == n) {
		result += (sum == target) * isNotNULL;
		return;
	}
	back(index + 1, sum + arr[index], 1);
	back(index + 1, sum, isNotNULL);
	return;
}

int main() {
	scanf("%d %d", &n, &target);
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	back(0, 0, 0);
	printf("%d", result);
	return 0;
}