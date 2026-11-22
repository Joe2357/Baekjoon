#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IDX 50
#define MAX_LEN 50

typedef struct Node {
	char serial[MAX_LEN + 1];
	int len;
	int digit_sum;
} Node;

Node arr[MAX_IDX];
int n;

int custom_asc(const void* a, const void* b) {
	Node *n1 = (Node*)a, *n2 = (Node*)b;

	if (n1->len > n2->len) {
		return 1;
	} else if (n1->len < n2->len) {
		return -1;
	} else {
		if (n1->digit_sum > n2->digit_sum) {
			return 1;
		} else if (n1->digit_sum < n2->digit_sum) {
			return -1;
		} else {
			int temp = strcmp(n1->serial, n2->serial);
			if (temp > 0) {
				return 1;
			} else if (temp < 0) {
				return -1;
			} else {
				return 0;
			}
		}
	}
}

void read_input() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", &arr[i].serial);
	}
	return;
}

void preprocess() {
	for (int i = 0; i < n; ++i) {
		arr[i].len = strlen(arr[i].serial);
		arr[i].digit_sum = 0;
		for (int j = 0; j < arr[i].len; ++j) {
			if ('0' <= arr[i].serial[j] && arr[i].serial[j] <= '9') {
				arr[i].digit_sum += (arr[i].serial[j] - '0');
			}
		}
	}
	qsort(arr, n, sizeof(Node), custom_asc);
	return;
}

int main() {
	read_input();
	preprocess();
	for (int i = 0; i < n; ++i) {
		printf("%s\n", arr[i].serial);
	}
	return 0;
}