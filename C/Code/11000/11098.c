#include <stdio.h>
#include <string.h>

int main(t) {
	for (scanf("%d", &t); t; t--) {
		int maxMoney = -1, tempMoney, n;
		char maxName[21], tempName[21];
		for (scanf("%d", &n); n; n--) {
			scanf("%d %s", &tempMoney, tempName);
			if (tempMoney > maxMoney) {
				maxMoney = tempMoney;
				strcpy(maxName, tempName);
			}
		}
		printf("%s\n", maxName);
	}
	return 0;
}