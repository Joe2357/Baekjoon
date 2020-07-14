#include <stdio.h>

int compare(int *a, int *b) {
	return *a - *b;
}

int main() {
	int arr[3];
	while (1) {
		for (int i = 0; i < 3; i++)
			scanf("%d", arr + i);
		qsort(arr, 3, sizeof(int), compare);
		if (!arr[0] && !arr[1] && !arr[2])
			return 0;
		else if (arr[0] + arr[1] <= arr[2])
			printf("Invalid\n");
		else if (arr[0] == arr[1] && arr[1] == arr[2])
			printf("Equilateral\n");
		else if (arr[0] == arr[1] || arr[1] == arr[2] || arr[2] == arr[0])
			printf("Isosceles\n");
		else
			printf("Scalene\n");
	}
}