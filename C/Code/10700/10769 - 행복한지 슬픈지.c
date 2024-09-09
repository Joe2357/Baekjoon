#include <stdio.h>
#include <string.h>

int main() {
	char string[300];
	int cnt_hap = 0;
	int cnt_sad = 0;
	fgets(string, 300, stdin);

	for (int i = 0; i < strlen(string) - 2; i++) {
		if (string[i] == ':' && string[i + 1] == '-') {
			if (string[i + 2] == ')')
				cnt_hap += 1;
			else if (string[i + 2] == '(')
				cnt_sad += 1;
		}
	}

	if (cnt_hap + cnt_sad == 0)
		printf("none");
	else if (cnt_hap > cnt_sad)
		printf("happy");
	else if (cnt_hap < cnt_sad)
		printf("sad");
	else if (cnt_hap == cnt_sad)
		printf("unsure");
	return 0;
}