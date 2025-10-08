#include <stdio.h>

#define MAX_SLOT (int)(1e5)
#define MAX_LEN (int)(1e5 + 1)
int n;

int main() {
	long long score = 0;
	int n;
	scanf("%d", &n);

	// game init
	int remained_two = n / 2;
	int occupied_two = 0;
	int remained_one = n % 2;
	int energy_gain = 0;

	// game iteration
	char cmd[MAX_LEN];
	scanf("%s", cmd);
	for (int i = 0; cmd[i] != '\0'; ++i) {
		switch (cmd[i]) {
			case '1': {
				if (remained_one > 0) {
					--remained_one;
					++energy_gain;
				} else if (remained_two > 0) {
					--remained_two;
					++remained_one;
					++energy_gain;
				} else if (occupied_two > 0) {
					--occupied_two;
					++remained_one;
				}
				break;
			}
			case '2': {
				if (remained_two > 0) {
					--remained_two;
					++occupied_two;
					++energy_gain;
				}
				break;
			}
		}
		score += energy_gain;
	}

	printf("%lld", score);
	return 0;
}