#include <stdio.h>

int main() {
	int happy = 0, sad = 0;
	char str[260];
	gets(str);
	for (int i = 0; str[i]; i++)				// brute force
		if (str[i] == ':' && str[i + 1] == '-') // maybe happy or sad
			if (str[i + 2] == ')')				// happy
				happy++, i += 2;
			else if (str[i + 2] == '(') // sad
				sad++, i += 2;
	if (!happy && !sad) // nothing
		printf("none");
	else if (happy == sad) // same
		printf("unsure");
	else if (happy > sad)
		printf("happy");
	else if (happy < sad)
		printf("sad");
	return 0;
}