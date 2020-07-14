#include <stdio.h>

int main(t) {
	int stack[100000], top = -1;
	long long sum = 0; // variable to get all values of stack
	for (scanf("%d", &t); t; t--) {
		int temp;
		scanf("%d", &temp);
		if (!temp) // pop
			sum -= stack[top--];
		else // push
			stack[++top] = temp,
			sum += temp;
	}
	printf("%lld", sum);
	return 0;
}