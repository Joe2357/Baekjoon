#include <stdio.h>

typedef struct Run {
	int speed;
	int time;
} Run;

#define MAX_IDX 1000
const int NONE_LEAD = 0;
const int BESSIE_LEAD = 1;
const int ELSIE_LEAD = 2;

Run Bessie[MAX_IDX];
Run Elsie[MAX_IDX];
int n, m;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &Bessie[i].speed, &Bessie[i].time);
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &Elsie[i].speed, &Elsie[i].time);
	}

	int rank_change = 0;
	int current_lead = NONE_LEAD;

	int distance_bessie = 0;
	int distance_elsie = 0;
	for (int i = 0, j = 0; i < n || j < m; i += (--Bessie[i].time == 0), j += (--Elsie[j].time == 0)) {
		distance_bessie += Bessie[i].speed, distance_elsie += Elsie[j].speed;
		if (distance_bessie > distance_elsie) {
			if (current_lead != BESSIE_LEAD) {
				rank_change += (current_lead != NONE_LEAD);
				current_lead = BESSIE_LEAD;
			} else {
				//
			}
		} else if (distance_bessie < distance_elsie) {
			if (current_lead != ELSIE_LEAD) {
				rank_change += (current_lead != NONE_LEAD);
				current_lead = ELSIE_LEAD;
			} else {
				//
			}
		} else {
			//
		}
	}

	printf("%d", rank_change);
	return 0;
}