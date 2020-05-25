#include <stdio.h>
#include <string.h>		// using strcmp function
#include <math.h>		// using pow function ( a ^ b )

int main() {
	long long result = 0;
	char arr[10][10] = { "black","brown","red","orange","yellow","green","blue","violet","grey","white" };	// set all input list
	for (int i = 0; i < 3; i++) {
		char str[10];
		scanf("%s", str);
		for (int j = 0; j < 10; j++) {		// searching list
			if (!strcmp(str, arr[j])) {		// target found
				if (!i)
					result += j * 10;
				else if (i == 1)
					result += j;
				else if (i == 2)
					result *= pow(10, j);	// 10 ^ j
				break;
			}
		}
	}
	printf("%lld", result);
	return 0;
}