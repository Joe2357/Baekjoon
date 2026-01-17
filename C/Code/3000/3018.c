#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef struct Participant {
	int known_song[2];
} Participant;

#define MAX_PEOPLE 100
#define MAX_DATE 50
const int BLOCK_SIZE = 25;
const int Seonyoung = 1;

Participant people[MAX_PEOPLE + 1];
int n, e;

int current_participants[MAX_PEOPLE];
int k;

bool isSeonyoungExists() {
	for (int i = 0; i < k; ++i) {
		if (current_participants[i] == Seonyoung) {
			return true;
		}
	}
	return false;
}

int main() {
	scanf("%d %d", &n, &e);
	while (e--) {
		scanf("%d", &k);
		for (int i = 0; i < k; ++i) {
			scanf("%d", &current_participants[i]);
		}
		if (isSeonyoungExists() == true) {
			for (int i = 0; i < k; ++i) {
				int c = current_participants[i];
				people[c].known_song[e / BLOCK_SIZE] |= (1 << (e % BLOCK_SIZE));
			}
		} else {
			int merged_songs[2] = {0};
			for (int i = 0; i < k; ++i) {
				int c = current_participants[i];
				merged_songs[0] |= people[c].known_song[0];
				merged_songs[1] |= people[c].known_song[1];
			}
			for (int i = 0; i < k; ++i) {
				int c = current_participants[i];
				people[c].known_song[0] = merged_songs[0];
				people[c].known_song[1] = merged_songs[1];
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		if ((people[i].known_song[0] == people[Seonyoung].known_song[0]) &&
			(people[i].known_song[1] == people[Seonyoung].known_song[1])) {
			printf("%d\n", i);
		}
	}
	return 0;
}