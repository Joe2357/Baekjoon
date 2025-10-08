#include <stdio.h>
#define SK 1
#define CY 0

int main() {
	int arr[1000] = {CY, SK, CY, SK}, n;
	char template[2][3] = {"CY", "SK"};
	scanf("%d", &n);
	for (int i = 4; i < n; i++)
		// make another player to take the last stone
		// to do that, SK must took n-1 stone to win
		if (arr[i - 1] == CY || arr[i - 3] == CY || arr[i - 4] == CY)
			arr[i] = SK;
		else
			arr[i] = CY;
	printf("%s", template[arr[--n]]);
}

void ex() {
	int n;
	scanf("%d", &n);
	if ((n % 7 == 1) || (n % 7 == 3))
		printf("CY");
	else
		printf("SK");
	return 0;
}