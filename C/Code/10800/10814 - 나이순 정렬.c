#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Person {
	int age, time;
	char name[101];
} PS;

PS arr[100000];

int compare(PS *a, PS *b) {
	if ((a->age > b->age) || (a->age == b->age) && (a->time > b->time))
		return 1;
	else
		return 0;
}

int main(n) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char nametemp[101];
		int agetemp;
		scanf("%d %s", &agetemp, nametemp);
		arr[i].age = agetemp;
		arr[i].time = i + 1;
		strcpy(arr[i].name, nametemp);
	}
	qsort(arr, n, sizeof(arr[0]), compare); // quicksort
	for (int i = 0; i < n; i++)
		printf("%d %s\n", arr[i].age, arr[i].name);
	return 0;
}