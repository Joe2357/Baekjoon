#include <stdio.h>
#define SK 0
#define CY 1

int main() {
	int arr[1000] = { CY, SK, CY }, n;
	char template[2][3] = { "SK", "CY" };
	scanf("%d", &n);
	for (int i = 3; i < n; i++)
		// focus on win
		// first, SK took 1 stone
		// So, play game with n-1 stone starts with CY
		if (arr[i - 1] == SK || arr[i - 3] == SK)
			arr[i] = CY;
		else
			arr[i] = SK;
	printf("%s", template[arr[--n]]); // print winner
	return 0;
}

void ex() {
	int n;
	scanf("%d", &n);
	if ((n - 1) % 4 % 2)
		printf("SK");
	else
		printf("CY");
	return 0;
}