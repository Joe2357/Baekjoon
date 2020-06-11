#include <stdio.h>

char str[51];	// target string
int minus;		// - already appeared?

int main() {
	scanf("%s", str);
	int i = 0, result = 0, temp = 0;
	while (str[i]) {								// check all character
		switch (str[i]) {							// check
			case '+':								// + or -
			case '-':
				result += (minus) ? -temp : temp;	// - already apeeared? - or +
				temp = 0;							// temp integer reset
				minus += (str[i] == '-');			// minus was appeared
				break;
			default:								// not + or - ( number )
				temp = temp * 10 + str[i] - '0';	// set temp interger
				break;
		}
		i++;
	}
	result += (minus) ? -temp : temp;				// last integer commited
	printf("%d", result);							// print result
	return 0;
}