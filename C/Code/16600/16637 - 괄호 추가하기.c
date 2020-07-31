#include <stdio.h>
#include <string.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))

char str[20], opArr[10];
long long numberArr[10], n, result = -1 * 1 << 31;

// return calculated number
long long calc(long long a, long long b, char op) {
	long long r;
	switch (op) {
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
	}
	return 0;
}

// brute force backtracking
void back(long long *arr, int index) {
	// backtrack init
	long long tarr[10] = { 0 };
	for (int i = 0; i < index; i++)
		tarr[i] = arr[i];

	if (index < n / 2) { // search not finished
		back(tarr, index + 1);
		tarr[index] = 1;
		back(tarr, index + 2);
		tarr[index] = 0;
	}
	else { // calc result
		long long numArr[10] = { 0 };
		for (int i = 0; i < n; i += 2)
			numArr[i / 2] = str[i] - '0';
		char tempStr[20] = { 0 };
		strcpy(tempStr, str);
		for (int i = 0; i < n / 2; i++) {
			if (tarr[i]) {
				numArr[i] = calc(numArr[i], numArr[i + 1], tempStr[i * 2 + 1]);
				numArr[i + 1] = numArr[i];
			}
		}
		for (int i = 0; i < n / 2; i++) {
			if (!tarr[i]) {
				numArr[i] = calc(numArr[i], numArr[i + 1], tempStr[i * 2 + 1]);
				numArr[i + 1] = numArr[i];
			}
			else
				numArr[i + 1] = numArr[i];
		}
		result = max(result, numArr[n / 2]);
	}
	return;
}

int main() {
	scanf("%lld %s", &n, str);

	// only 1 number
	if (n == 1) {
		printf("%s", str);
		return 0;
	}

	// seperate number, operation
	for (int i = 0; i < n; i++)
		if (i % 2)
			opArr[i / 2] = str[i];
		else
			numberArr[i / 2] = str[i] - '0';

	// first init
	result = str[0] - '0';
	for (int i = 2; i < n; i += 2)
		result = calc(result, str[i] - '0', str[i - 1]);

	// calculate all cases
	long long tempArr[10] = { 0 };
	back(tempArr, 0);
	back(tempArr, 1);

	// print result
	printf("%lld", result);
	return 0;
}