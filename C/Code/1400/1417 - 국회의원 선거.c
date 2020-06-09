#include <stdio.h>

int main() {
	int n, arr[1001] = { 0 }, max = 0, dasom, result = 0;
	scanf("%d", &n);
	scanf("%d", &dasom);									// target get
	for (int i = 0; i < n - 1; i++) {
		int temp;
		scanf("%d", &temp);									// competitor get
		arr[temp]++;										// arr[n] = competitor's amount who get n votes
		if (temp > max)
			max = temp;										// competitor's maximun votes
	}
	while (dasom <= max) {									// dasom must have more votes than competitors 
		result++, arr[max]--, arr[max-1]++, dasom++;
		if (!arr[max])
			max--;
	}
	printf("%d", result);
	return 0;
}