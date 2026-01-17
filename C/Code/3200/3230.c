#include <stdio.h>
#include <stdlib.h>

typedef struct Participant {
	int number;
	int rank;
} Participant;

#define MAX_IDX 100

Participant participants[MAX_IDX];
int n, m;

int rank_asc(const void* a, const void* b) {
	if (((Participant*)a)->rank > ((Participant*)b)->rank) {
		return 1;
	} else if (((Participant*)a)->rank < ((Participant*)b)->rank) {
		return -1;
	} else {
		return 0;
	}
}

// start부터 end-1까지 뒤집기
void reverse(Participant* arr, int start, int end) {
	for (int i = start; i < (start + end) / 2; ++i) {
		Participant temp = arr[i];
		arr[i] = arr[start + end - 1 - (i - start)];
		arr[start + end - 1 - (i - start)] = temp;
	}
	return;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		participants[i].number = i + 1;
		scanf("%d", &participants[i].rank);

		for (int j = 0; j < i; ++j) {
			participants[j].rank += (participants[j].rank >= participants[i].rank);
		}
	}
	qsort(participants, n, sizeof(Participant), rank_asc);
	reverse(participants, 0, m);
	for (int i = 0; i < m; ++i) {
		scanf("%d", &participants[i].rank);

		for (int j = 0; j < i; ++j) {
			participants[j].rank += (participants[j].rank >= participants[i].rank);
		}
	}

	for (int i = 1; i <= 3; ++i) {
		for (int j = 0; j < m; ++j) {
			if (participants[j].rank == i) {
				printf("%d\n", participants[j].number);
				break;
			}
		}
	}
	return 0;
}