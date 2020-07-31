#include <stdio.h>
#include <string.h>
#define max(a, b) (a > b) ? a : b

int main() {
	// init
	int result[10010] = { 0 }, Max, minus[2] = { 0 };
	char str[2][10010] = { 0 };
	scanf("%s %s", str[0], str[1]);

	// check whether input is minus
	for (int i = 0; i < 2; i++)
		if (str[i][0] == '-') {
			minus[i] = 1;
			for (int a = 0; str[i][a]; a++)
				str[i][a] = str[i][a + 1];
		}

	if (!((minus[0] + minus[1]) % 2)) { // just need to add numbers
		Max = max(strlen(str[0]), strlen(str[1]));
		for (int i = 0; i < 2; i++) {
			for (int j = 0; str[i][j]; j++) // add numbers
				result[Max - strlen(str[i]) + j] += (str[i][j] - '0');
			for (int j = Max; j; j--) // up-numbers ( over 10 )
				if (result[j] / 10)
					result[j - 1] += result[j] / 10, result[j] %= 10;
		}

		// print result
		if (minus[0])
			printf("-");
		for (int i = 0; i < Max; i++)
			printf("%d", result[i]);
	}
	else { // need to subtract numbers
		Max = max(strlen(str[0]), strlen(str[1]));
		for (int i = 0; i < 2; i++) // add numbers depoend on minus
			for (int j = 0; str[i][j]; j++)
				if (minus[i])
					result[Max - strlen(str[i]) + j] -= (str[i][j] - '0');
				else
					result[Max - strlen(str[i]) + j] += (str[i][j] - '0');

		// find start of numbers
		int a = 0, isMinus = 0;
		while (!result[a])
			a++;

		if (a > Max) { // result was 0
			printf("0");
			return 0;
		}
		else if (result[a] < 0) { // result is minus ( smaller than 0 )
			isMinus = 1;
			for (int b = a; b < Max; b++)
				result[b] *= -1;
		}

		// down numbers ( under 0 )
		for (int b = Max - 1; b; b--)
			if (result[b] < 0)
				result[b] += 10, result[b - 1]--;

		// find start of numbers
		while (!result[a])
			a++;

		// print result
		if (isMinus)
			printf("-");
		for (int i = a; i < Max; i++)
			printf("%d", result[i]);
	}
	return 0;
}