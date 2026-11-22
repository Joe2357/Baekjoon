#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef struct IPAddress {
	int a, b, c, d;
	unsigned int ip;
} IP;

#define MAX_IDX 1000

IP address[MAX_IDX];
int n;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a, b, c, d;
		scanf("%d.%d.%d.%d", &a, &b, &c, &d);
		address[i] = (IP){a, b, c, d};
		address[i].ip = (a * (1 << 24) +
						 b * (1 << 16) +
						 c * (1 << 8) +
						 d * (1 << 0));
	}

	IP networkMask = (IP){0, 0, 0, 0, 0};
	int left = 31;
	for (left = 31; left >= 0; --left) {
		bool isAllSame = true;
		bool isThere_a_Digit = ((address[0].ip & (1 << left)) > 0);

		for (int j = 1; j < n; ++j) {
			if (isThere_a_Digit != ((address[j].ip & (1 << left)) > 0)) {
				isAllSame = false;
				break;
			}
		}

		if (isAllSame == false) {
			break;
		} else {
			networkMask.ip += (1 << left);
		}
	}

	networkMask.a = (networkMask.ip >> 24);
	networkMask.b = ((networkMask.ip - networkMask.a * (1 << 24)) >> 16);
	networkMask.c = ((networkMask.ip - networkMask.a * (1 << 24) - networkMask.b * (1 << 16)) >> 8);
	networkMask.d = ((networkMask.ip - networkMask.a * (1 << 24) - networkMask.b * (1 << 16) - networkMask.c * (1 << 8)) >> 0);

	IP networkIP = networkMask;
	for (int i = 0; i < n; ++i) {
		networkIP.a &= address[i].a;
		networkIP.b &= address[i].b;
		networkIP.c &= address[i].c;
		networkIP.d &= address[i].d;
	}

	printf("%d.%d.%d.%d\n", networkIP.a, networkIP.b, networkIP.c, networkIP.d);
	printf("%d.%d.%d.%d\n", networkMask.a, networkMask.b, networkMask.c, networkMask.d);
	return 0;
}