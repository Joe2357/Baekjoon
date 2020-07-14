#include <stdio.h>
#include <math.h>

int main() {
	int arr[7] = { 0 }, count[2] = { 0 }, result;
	for (int i = 0; i < 3; i++) {
		int temp;
		scanf("%d", &temp);
		arr[temp]++;											// counting
		if (arr[temp] > count[0])								// finding biggest value
			count[0]++, count[1] = temp;
		else if ((arr[temp] == count[0]) && (temp > count[1]))	// value appears more than 2 times
			count[1] = temp;
	}
	result = count[1] * pow(10, count[0]);						// calc
	switch (count[0]) {											// powering
		case 3:
			result += 10000;
			break;
		case 2:
			result += 1000;
			break;
		case 1:
			result *= 10;
			break;
	}
	printf("%d", result);
	return 0;
}