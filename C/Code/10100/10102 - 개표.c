#include <stdio.h>

int main() {
	int vote[2] = { 0 }, n;
	char str[16];
	scanf("%d %s", &n, str);
	for (int i = 0; i < n; i++) // for all votes
		vote[str[i] - 'A']++;
	// print result
	if (vote[0] < vote[1])
		printf("B");
	else if (vote[0] > vote[1])
		printf("A");
	else
		printf("Tie");
	return 0;
}