#include <stdio.h>
#define MAX 1000000001
#define max(a, b) (((a) < (b)) ? (b) : (a))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int result[2] = {-MAX, MAX};

int evil(int n1, int n2, int op) {
	switch (op) {
		case 0:
			return n1 + n2;
		case 1:
			return n1 - n2;
		case 2:
			return n1 * n2;
		case 3:
			return n1 / n2;
	}
}

void back(int* arr, int* op, int n, int t) {
	int tempArr[11], tempOp[4];
	for (int i = 0; i < n; i++)
		tempArr[i] = arr[i];
	for (int i = 0; i < 4; i++)
		tempOp[i] = op[i];
	if (n == t) {
		result[0] = max(result[0], arr[n - 1]);
		result[1] = min(result[1], arr[n - 1]);
		return;
	}
	for (int i = 0; i < 4; i++)
		if (op[i]) {
			tempOp[i]--;
			tempArr[t] = evil(arr[t - 1], arr[t], i);
			back(tempArr, tempOp, n, t + 1);
			tempOp[i]++;
		}
	return;
}

int main(n) {
	int arr[11], op[4];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	for (int i = 0; i < 4; i++)
		scanf("%d", op + i);
	back(arr, op, n, 1);
	printf("%d\n%d", result[0], result[1]);
	return 0;
}