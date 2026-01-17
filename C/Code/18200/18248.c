#include <stdio.h>
#include <stdlib.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef struct Person {
	int id, hear_count;
} Person;

#define MAX_PERSON 1000
#define MAX_BELL 100

bool bell_hear[MAX_PERSON][MAX_BELL + 1];
Person persons[MAX_PERSON];
int n, m;

int hear_asc(const void* a, const void* b) {
	Person* pa = (Person*)a;
	Person* pb = (Person*)b;

	if (pa->hear_count != pb->hear_count) {
		return pa->hear_count - pb->hear_count;
	} else {
		return pa->id - pb->id;
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		int hear_cnt = 0;
		for (int j = 0; j < m; ++j) {
			int hear;
			scanf("%d", &hear);
			bell_hear[i][j] = ((hear == 1) ? true : false);
			hear_cnt += hear;
		}
		persons[i] = (Person){i, hear_cnt};
	}

	qsort(persons, n, sizeof(Person), hear_asc);

	bool ret = true;
	for (int i = 1; i < n; ++i) {
		bool isValid = true;
		for (int j = 0; j < m; ++j) {
			isValid &= (bell_hear[persons[i - 1].id][j] <= bell_hear[persons[i].id][j]);
		}
		ret &= isValid;
	}

	printf("%s", (ret == true ? "YES" : "NO"));
	return 0;
}