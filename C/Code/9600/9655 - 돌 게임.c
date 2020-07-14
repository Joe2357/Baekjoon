#include <stdio.h>
#define SK 1
#define CY 0

int main() {
	int arr[1001] = { 0, SK, CY, SK }, n;
	char template[2][3] = { "CY", "SK" };
	scanf("%d", &n);
	for (int i = 4; i <= n; i++)
		// focus to SK
		// if SK has a probabilty to win, Set to SK
		// if not, set to CY
		if (arr[i - 1] == CY || arr[i - 3] == CY)
			arr[i] = SK;
		else
			arr[i] = CY;
	printf("%s", template[arr[n]]);
	return 0;
}

void ex() {
	int n;
	scanf("%d", &n);
	if ((n % 4) % 2)
		printf("SK");
	else
		printf("CY");
	return 0;
}