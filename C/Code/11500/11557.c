#include <stdio.h>

#define MAX_LEN 20
#define MAX_SCHOOL 100

typedef struct School {
	char name[MAX_LEN + 1];
	int l;
} SC;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		SC best_school = {"", 0};

		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			char input_school_name[MAX_LEN + 1];
			int input_l;
			scanf("%s %d", input_school_name, &input_l);

			if (best_school.l < input_l) { // 복사
				for (int j = 0; j < MAX_LEN; ++j) {
					best_school.name[j] = input_school_name[j];
				}
				best_school.l = input_l;
			}
		}

		printf("%s\n", best_school.name);
	}
	return 0;
}