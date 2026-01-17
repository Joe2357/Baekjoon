#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_LEN 30
#define MAX_IDX 10

char input[MAX_IDX + 1][MAX_LEN + 1];
bool isAlive[MAX_IDX + 1];
int n;

void init() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		isAlive[i] = true;
		scanf("%s", input[i]);
	}
	return;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		init();

		for (int i = 0; input[0][i] != '\0'; ++i) {
			int rock = 0, scissors = 0, paper = 0;
			for (int j = 0; j < n; ++j) {
				if (isAlive[j] == true) {
					rock += (input[j][i] == 'R');
					scissors += (input[j][i] == 'S');
					paper += (input[j][i] == 'P');
				}
			}

			if (rock == 0) {
				if (scissors > 0) {
					for (int j = 0; j < n; ++j) {
						if (isAlive[j] == true && input[j][i] == 'P') {
							isAlive[j] = false;
						}
					}
				}
			} else if (scissors == 0) {
				if (paper > 0) {
					for (int j = 0; j < n; ++j) {
						if (isAlive[j] == true && input[j][i] == 'R') {
							isAlive[j] = false;
						}
					}
				}
			} else if (paper == 0) {
				if (rock > 0) {
					for (int j = 0; j < n; ++j) {
						if (isAlive[j] == true && input[j][i] == 'S') {
							isAlive[j] = false;
						}
					}
				}
			} else {
				;
			}
		}

		int ret = 0;
		for (int i = 0; i < n; ++i) {
			ret += isAlive[i];
		}
		if (ret == 1) {
			for (int i = 0; i < n; ++i) {
				if (isAlive[i] == true) {
					printf("%d\n", i + 1);
					break;
				}
			}
		} else {
			printf("0\n");
		}
	}
	return 0;
}