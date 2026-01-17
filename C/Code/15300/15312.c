#include <stdio.h>

#define MAX_LEN 2000
const int MOD = 10;
const int ALPHABET[26] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};

char my_name[MAX_LEN + 1], her_name[MAX_LEN + 1];
int arr[2 * MAX_LEN];

int main() {
	scanf("%s %s", my_name, her_name);
	int length;
	for (int i = 0; my_name[i] != '\0'; length = ++i) {
		arr[2 * i] = ALPHABET[my_name[i] - 'A'];
		arr[2 * i + 1] = ALPHABET[her_name[i] - 'A'];
	}

	for (int i = 2 * length - 1; i > 1; --i) {
		for (int j = 0; j < i; ++j) {
			arr[j] = (arr[j] + arr[j + 1]) % MOD;
		}
	}
	printf("%d%d", arr[0], arr[1]);
	return 0;
}