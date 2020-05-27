#include <stdio.h>

int arr[20], result, n, target;

void back(int index, int sum, int isNotNULL) {
	if (index == n) {								// if subset of array
		result += (sum == target) * isNotNULL;		// result += 1 if profer condition & not empty subset
		return;
	}
	back(index + 1, sum + arr[index], 1);			// add current value
	back(index + 1, sum, isNotNULL);				// not add current value
	return;
}

int main() {
	scanf("%d %d", &n, &target);
	for (int i = 0; i < n; i++)		// array input
		scanf("%d", arr + i);
	back(0, 0, 0);					// function call
	printf("%d", result);
	return 0;
}