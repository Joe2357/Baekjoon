#include <stdio.h>

int main() {
	char str[3];
	scanf("%s", str);
	float result = 'E' - str[0];    // "ABCDE"[str[0] - 'A']
	if (str[0] == 'F')              // fail
		result = 0;
	switch (str[1]) {
		case '+':                       // + 0.3
			result += 0.3;
			break;
		case '-':                       // - 0.3
			result -= 0.3;
			break;
	}
	printf("%.1f", result);
	return 0;
}