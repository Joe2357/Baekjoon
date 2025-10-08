#include <stdio.h>
#include <string.h>

int cmp(char* a, char* b) {
	return (strcmp(a, b) > 0);
}
int compare(int* a, int* b) {
	return *a - *b;
}

int main() {
	char str[500000][21], tempstr[21];
	int arr[500000] = {0}, result = 0, n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", str[i]);
	qsort(str, n, sizeof(char) * 21, cmp);
	for (; m; m--) {
		scanf("%s", tempstr);
		int start = 0, end = n - 1, mid;
		while (start <= end) {
			mid = (start + end) / 2;
			int temp = strcmp(tempstr, str[mid]);
			if (!temp)
				arr[result++] = mid, start = n + 1;
			else if (temp > 0)
				start = mid + 1;
			else
				end = mid - 1;
		}
	}
	qsort(arr, result, sizeof(int), compare);
	printf("%d\n", result);
	for (int i = 0; i < result; i++)
		printf("%s\n", str[arr[i]]);
}