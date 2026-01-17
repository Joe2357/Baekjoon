#include <stdio.h>
#include <stdlib.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 50
const int MAX_VAL = 1000;

int arr[MAX_IDX];
int n;
int target;

int asc(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

void read_input() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}
	qsort(arr, n, sizeof(int), asc);
	scanf("%d", &target);
	return;
}

bool target_in_array() {
	for (int i = 0; i < n; ++i) {
		if (arr[i] == target) {
			return true;
		}
	}
	return false;
}

int main() {
	read_input();

	if (target_in_array() == true) {
		printf("0");
		return 0;
	}

	int max_value_under_target = 0, min_value_over_target = MAX_VAL + 1;
	for (int i = 0; i < n; ++i) {
		if (arr[i] <= target && arr[i] > max_value_under_target) {
			max_value_under_target = arr[i];
		}
		if (arr[i] >= target && arr[i] < min_value_over_target) {
			min_value_over_target = arr[i];
		}
	}

	if (max_value_under_target < min_value_over_target) {
		printf("%d",
			   (target - max_value_under_target) * (min_value_over_target - target) - 1);
	} else {
		printf("0");
	}

	return 0;
}