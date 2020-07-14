#include <stdio.h>

int main(t) {
	for (scanf("%d", &t); t; t--) {
		int result, option; // result = price of car
		scanf("%d %d", &result, &option);
		for (; option; option--) {
			int q, p;
			scanf("%d %d", &q, &p); // quantity * price
			result += q * p;
		}
		printf("%d\n", result);
	}
	return 0;
}