#include <stdio.h>
#define min(a, b) (((a) > (b)) ? (b) : (a))

int main() {
	int arr[6], sum = 0, minScore = 101;
	for (int i = 0; i < 6; i++) {
		// add all scores
		scanf("%d", arr + i);
		sum += arr[i];
	}
	for (int i = 0; i < 4; i++)
		minScore = min(minScore, arr[i]); // minimum score from 1 to 4
	sum -= (minScore + min(arr[4], arr[5])); // all scores - 1~4's min score - 5~6's min score
	printf("%d", sum);
	return 0;
}