#include <stdio.h>
#define M_I (int)1e6

int arr[2][M_I];
int len[2];
int u, d;

int main() {
	scanf("%d %d", &len[0], &len[1]);
	for (int i = 0; i < len[0]; ++i)
		scanf("%d", arr[0] + i);
	for (int i = 0; i < len[1]; ++i)
		scanf("%d", arr[1] + i);

	while (u < len[0] && d < len[1])
		if (arr[0][u] <= arr[1][d])
			printf("%d ", arr[0][u++]);
		else
			printf("%d ", arr[1][d++]);

	for (; u < len[0]; ++u)
		printf("%d ", arr[0][u]);
	for (; d < len[1]; ++d)
		printf("%d ", arr[1][d]);

	return 0;
}