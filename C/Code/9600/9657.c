#include <stdio.h>
#define SK 1
#define CY 0

int main() {
	int arr[1001] = {0, SK, CY, SK, SK}, n;
	char template[2][3] = {"CY", "SK"};
	scanf("%d", &n);
	for (int i = 5; i <= n; i++) {
		// focus on winning
		if (arr[i - 1] == CY || arr[i - 3] == CY || arr[i - 4] == CY)
			arr[i] = SK;
		else
			arr[i] = CY;
	}
	printf("%s", template[arr[n]]);
	return 0;
}

void ex() {
	int n;
	scanf("%d", &n);
	if (!(n % 7) || (n % 7 == 2))
		printf("CY");
	else
		printf("SK");
	return 0;
}