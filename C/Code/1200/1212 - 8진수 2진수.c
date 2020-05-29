#include <stdio.h>

int main() {
	int i = 1;					// starts from 1
	char grid[8][4] = {			// binary grid
		"000", "001", "010", "011",
		"100", "101", "110", "111" }, str[333335];	// string array
	scanf("%s", str);				// get input
	if (str[0] == '0' && !str[1]) {	// if input == "0"
		printf("0");
		return 0;
	}
	switch (str[0]) {				// first letter
		case '1':
			printf("1");
			break;
		case '2':
			printf("10");
			break;
		case '3':
			printf("11");
			break;
		case '4':
		case '5':
		case '6':
		case '7':
			printf("%s", grid[str[0] - '0']);
			break;
	}
	while (str[i])								// while end
		printf("%s", grid[str[i++] - '0']);
	return 0;
}