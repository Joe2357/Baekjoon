#include <stdio.h>

#define MAX_INDEX (int)5e4

int arr[MAX_INDEX];
int n;

int explode(int s) {
	if (s == n) {
		return;
	}

	int t = arr[s++];
	while (s < n) {
		if (arr[s] > t) {
			t = arr[s++];
		}
		else {
			break;
		}
	}
	printf("%d\n", s);
	while (s < n) {
		if (arr[s] < t) {
			t = arr[s++];
		}
		else {
			break;
		}
	}
	return s;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", arr + i);
	}

	int term = 0;
	while (term < n) {
		term = explode(term);
	}
	return 0;
}