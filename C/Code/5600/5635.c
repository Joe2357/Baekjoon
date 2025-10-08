#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_LEN 15

typedef struct Date {
	int year, month, day;
} DATE;
typedef struct Student {
	char name[MAX_LEN + 1];
	DATE birth;
} STUDENT;

STUDENT students[MAX_STUDENTS];
int n;

int student_asc(const void* a, const void* b) {
	DATE da = ((STUDENT*)a)->birth;
	DATE db = ((STUDENT*)b)->birth;
	if (da.year != db.year) {
		return da.year - db.year;
	} else if (da.month != db.month) {
		return da.month - db.month;
	} else
		return da.day - db.day;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s %d %d %d", students[i].name, &students[i].birth.day, &students[i].birth.month, &students[i].birth.year);
	}
	qsort(students, n, sizeof(STUDENT), student_asc);
	printf("%s\n%s\n", students[n - 1].name, students[0].name);
	return 0;
}