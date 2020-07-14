#include <stdio.h>

int main(n, trash) {
	int arr[100000] = { 0 }, max = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
		if (arr[i] > max)						// temporary max value
			max = arr[i], trash = -1;
		else if (trash == -1 || arr[i] < trash)	// next value of the temporary max value is no matter, 
			trash = arr[i];
		else {									// but next of them must be decending value
			printf("NO");
			return 0;
		}
	}
	trash = 0;
	for (int i = 0; i < n; i++)
		if (trash == arr[i])					// pop
			printf("-\n");
		else {
			while (trash < arr[i]) {			// push until target value in stack
				trash++;
				printf("+\n");
			}
			printf("-\n");						// pop
		}
	return 0;
}