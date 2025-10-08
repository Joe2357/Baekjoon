#include <stdio.h>

#define MAX_PEOPLE 50

typedef struct Person {
	int weight;
	int height;
	int rank;
} PERSON;

PERSON people[MAX_PEOPLE];
int n;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &people[i].weight, &people[i].height);
		people[i].rank = 1; // Initialize rank to 1
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; j++) {
			people[i].rank += (people[i].weight < people[j].weight && people[i].height < people[j].height);
		}
	}
	for (int i = 0; i < n; ++i) {
		printf("%d ", people[i].rank);
	}
	return 0;
}