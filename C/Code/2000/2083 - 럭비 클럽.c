#include <stdio.h>

int main(age, weight) {
	while (1) {
		char name[11];
		scanf("%s %d %d", name, &age, &weight);
		if (name[0] == '#')						// eof
			return 0;
		if ((age > 17) || (weight >= 80))		// if condition
			printf("%s Senior\n", name);
		else
			printf("%s Junior\n", name);
	}
}