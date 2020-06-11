#include <stdio.h>

int main(n, temp) {
	float max = -1, sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);								// i'th subject score
		sum += temp, max = (max > temp) ? max : temp;	// if score > max, max will change
	}
	printf("%f", sum / max * 100 / n);					// print new average
	return 0;
}