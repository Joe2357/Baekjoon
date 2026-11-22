#include <stdio.h>

#define NUMBER_OF_STACK 4
const int NONE = -1;
const int ZERO = 0;

int n;
int stack[NUMBER_OF_STACK];

#define max(a, b) (((a) > (b)) ? (a) : (b))
int main() {
	scanf("%d", &n);
	for (int i = 0; i < NUMBER_OF_STACK; ++i) {
		stack[i] = ZERO;
	}

	for (int i = 0; i < n; ++i) {
		int input;
		scanf("%d", &input);

		int idx = NONE, temp = NONE;
		for (int j = 0; j < NUMBER_OF_STACK; ++j) {
			if (temp < stack[j] && stack[j] < input) {
				idx = j, temp = stack[j];
			}
		}

		if (idx == NONE) {
			printf("NO");
			return 0;
		} else {
			stack[idx] = input;
		}
	}

	printf("YES");
	return 0;
}