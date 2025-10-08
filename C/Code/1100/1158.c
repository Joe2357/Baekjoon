#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 5000

bool visited[MAX_IDX + 1];
int result[MAX_IDX];
int n, k;

void print_result() {
	printf("<");
	for (int i = 0; i < n - 1; ++i) {
		printf("%d, ", result[i]);
	}
	printf("%d>", result[n - 1]);
	return;
}

int main() {
	scanf("%d %d", &n, &k);

	int current_index = 0, temp = 0;
	for (int i = 0; i < n; ++i) {
		for (temp = 0; temp < k;) {
			temp += (visited[current_index] == false);
			if (temp == k) {
				break;
			}
			current_index = (current_index + 1) % n;
		}
		visited[current_index] = true;
		result[i] = current_index + 1;
	}
	print_result();
	return 0;
}