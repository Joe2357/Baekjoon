#include <stdio.h>
#include <stdlib.h>

#define MAX_PEOPLE (int)(1e5)
#define MAX_LEN 100

typedef struct Person {
	int age;
	int idx;
	char name[MAX_LEN + 1];
} Person;

Person people[MAX_PEOPLE];
int n;

void read_input() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %s", &people[i].age, people[i].name);
		people[i].idx = i;
	}
}

int age_asc_idx_asc(const void* a, const void* b) {
	Person* pa = (Person*)a;
	Person* pb = (Person*)b;
	if (pa->age != pb->age) {
		return pa->age - pb->age;
	} else {
		return pa->idx - pb->idx;
	}
}

int main() {
	read_input();
	qsort(people, n, sizeof(Person), age_asc_idx_asc);
	for (int i = 0; i < n; ++i) {
		printf("%d %s\n", people[i].age, people[i].name);
	}
	return 0;
}