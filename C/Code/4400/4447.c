#include <stdio.h>

#define MAX_LEN 25

int main() {
	int n;
	scanf("%d ", &n);
	while (n--) {
		char name[MAX_LEN + 1];
		gets(name);

		int cnt_b = 0, cnt_g = 0;
		for (int i = 0; name[i] != '\0'; ++i) {
			cnt_b += (name[i] == 'b' || name[i] == 'B');
			cnt_g += (name[i] == 'g' || name[i] == 'G');
		}

		if (cnt_b > cnt_g) {
			printf("%s is A BADDY\n", name);
		} else if (cnt_b < cnt_g) {
			printf("%s is GOOD\n", name);
		} else {
			printf("%s is NEUTRAL\n", name);
		}
	}
	return 0;
}