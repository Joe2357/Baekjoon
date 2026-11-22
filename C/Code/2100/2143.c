#include <stdio.h>

#define MAX_IDX 1000

int t;
int a[MAX_IDX], n;
int sum_a[MAX_IDX * MAX_IDX], l_a;
int b[MAX_IDX], m;
int sum_b[MAX_IDX * MAX_IDX], l_b;

int asc_cmp(int* a, int* b) {
	return *a > *b;
}
int desc_cmp(int* a, int* b) {
	return *a < *b;
}

void read_input() {
	scanf("%d", &t);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d", b + i);
	}
	return;
}

void preprocess() {
	for (int i = 0; i < n; ++i) {
		int temp = a[i];
		sum_a[l_a++] = temp;
		for (int j = i + 1; j < n; ++j) {
			temp += a[j];
			sum_a[l_a++] = temp;
		}
	}
	qsort(sum_a, l_a, sizeof(int), asc_cmp);

	for (int i = 0; i < m; ++i) {
		int temp = b[i];
		sum_b[l_b++] = temp;
		for (int j = i + 1; j < m; ++j) {
			temp += b[j];
			sum_b[l_b++] = temp;
		}
	}
	qsort(sum_b, l_b, sizeof(int), desc_cmp);
	return;
}

long long solve() {
	int l = 0, r = 0;
	long long ret = 0;

	while (l < l_a && r < l_b) {
		int temp = sum_a[l] + sum_b[r];

		if (temp == t) {
			long long sub_l = 1;
			while (l + sub_l < l_a && sum_a[l] == sum_a[l + sub_l]) {
				++sub_l;
			}
			long long sub_r = 1;
			while (r + sub_r < l_b && sum_b[r] == sum_b[r + sub_r]) {
				++sub_r;
			}

			ret += (sub_l * sub_r);
			l += sub_l, r += sub_r;
		} else if (temp < t) {
			++l;
		} else {
			++r;
		}
	}
	return ret;
}

int main() {
	read_input();
	preprocess();

	printf("%lld", solve());
	return 0;
}