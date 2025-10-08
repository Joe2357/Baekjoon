#include <stdio.h>
#include <string.h>

typedef struct Pokemon {
	char name[21];
	int num;
} PK;

int cmp(PK* a, PK* b) {
	long long temp =
		strcmp(a->name, b->name);
	return (temp > 0);
}

int main(n, m) {
	char str[100000][21] = {0};
	PK arr[100000];
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", str[i]);
		strcpy(arr[i].name, str[i]);
		arr[i].num = i + 1;
	}
	qsort(arr, n, sizeof(PK), cmp);
	for (; m; m--) {
		char tempstr[21];
		scanf("%s", tempstr);
		if (tempstr[0] <= '9') {
			int temp = 0;
			for (int i = 0; tempstr[i]; i++)
				temp *= 10, temp += tempstr[i] - '0';
			printf("%s\n", str[temp - 1]);
		} else { // binary search
			int start = 0, end = n;
			while (start <= end) {
				int mid = (start + end) / 2;
				long long value = strcmp(arr[mid].name, tempstr);
				if (!value) {
					printf("%d\n", arr[mid].num);
					start = n;
				} else if (value < 0)
					start = mid + 1;
				else
					end = mid - 1;
			}
		}
	}
	return 0;
}