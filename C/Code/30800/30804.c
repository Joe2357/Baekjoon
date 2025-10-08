#include <stdio.h>

typedef struct Node {
	int type;
	int cnt;
} ND;

#define MAX_IDX 200000
#define MAX_TYPE 9
const int NONE = -1;

ND fruit[MAX_IDX];
int len;
int n;

#define max(a, b) (((a) > (b)) ? (a) : (b))

int main() {
	scanf("%d", &n);

	/* compression */
	int temp_type = NONE;
	int temp_cnt = 0;
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);

		if (a == temp_type) {
			++temp_cnt;
		} else {
			if (temp_type != NONE) {
				fruit[len++] = (ND){temp_type, temp_cnt};
			}
			temp_type = a;
			temp_cnt = 1;
		}
	}
	fruit[len++] = (ND){temp_type, temp_cnt};

	/* solve */
	if (len <= 2) {
		printf("%d", n);
	} else {
		int result = 0;
		int left = 0;
		int current_cnt = 0;

		int using_group[MAX_TYPE + 1] = {0};
		int group_cnt = 0;

		for (int i = 0; i < len; ++i) {
			current_cnt += fruit[i].cnt;
			if (using_group[fruit[i].type] == 0) {
				++group_cnt;
			}
			using_group[fruit[i].type] += 1;

			while (group_cnt > 2) {
				current_cnt -= fruit[left].cnt;
				using_group[fruit[left].type] -= 1;
				if (using_group[fruit[left].type] == 0) {
					--group_cnt;
				}

				++left;
			}
			result = max(result, current_cnt);
		}
		result = max(result, current_cnt);

		printf("%d", result);
	}

	return 0;
}