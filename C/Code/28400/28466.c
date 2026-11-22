#include <stdio.h>

typedef struct Teammate {
	int score, sky, ground;
} Teammate;

#define MAX_SKY 10
#define MAX_GROUND 12
#define MAX_PEOPLE (int)(1e6)
#define MAX_PERSON_PER_CELL 3

int n;
int sky[MAX_SKY][MAX_SKY];
int ground[MAX_GROUND][MAX_GROUND];
int user_map[MAX_SKY][MAX_GROUND][MAX_PERSON_PER_CELL];

Teammate teammates[MAX_SKY * MAX_GROUND * MAX_PERSON_PER_CELL];
int teammate_count = 0;

#define max(a, b) ((a) > (b) ? (a) : (b))

void read_input() {
	scanf("%d", &n);
	for (int i = 0; i < MAX_SKY; ++i) {
		for (int j = 0; j < MAX_SKY; ++j) {
			scanf("%d", &sky[i][j]);
		}
	}
	for (int i = 0; i < MAX_GROUND; ++i) {
		for (int j = 0; j < MAX_GROUND; ++j) {
			scanf("%d", &ground[i][j]);
		}
	}

	for (int i = 0; i < n; ++i) {
		int score;
		char user[3];
		scanf("%d %s", &score, user);

		int user_sky = user[0] - '0',
			user_ground = user[1] - 'A';

		// user_map에 score를 저장
		// 각 셀에 최대 3명까지 저장 가능하며, 높은 3개의 점수를 유지
		int* cell = user_map[user_sky][user_ground];
		for (int j = 0; j < MAX_PERSON_PER_CELL; ++j) {
			if (score > cell[j]) {
				for (int k = MAX_PERSON_PER_CELL - 1; k > j; --k) {
					cell[k] = cell[k - 1];
				}
				cell[j] = score;
				break;
			}
		}
	}
	return;
}

void process_data() {
	for (int i = 0; i < MAX_SKY; ++i) {
		for (int j = 0; j < MAX_GROUND; ++j) {
			int* cell = user_map[i][j];
			for (int k = 0; k < MAX_PERSON_PER_CELL; ++k) {
				if (cell[k] > 0) {
					teammates[teammate_count++] = (Teammate){cell[k], i, j};
				}
			}
		}
	}
	return;
}

void debug_print() {
	for (int i = 0; i < teammate_count; ++i) {
		printf("Teammate %d: score=%d, sky=%d, ground=%d\n",
			   i, teammates[i].score, teammates[i].sky, teammates[i].ground);
	}
	return;
}

int solve() {
	int ret = 0;
	for (int x = 0; x < teammate_count; ++x) {
		for (int y = x + 1; y < teammate_count; ++y) {
			int temp_score = teammates[x].score + teammates[y].score +
							 sky[teammates[x].sky][teammates[y].sky] +
							 ground[teammates[x].ground][teammates[y].ground];
			for (int z = y + 1; z < teammate_count; ++z) {
				int total_score = temp_score + teammates[z].score +
								  sky[teammates[x].sky][teammates[z].sky] +
								  sky[teammates[y].sky][teammates[z].sky] +
								  ground[teammates[x].ground][teammates[z].ground] +
								  ground[teammates[y].ground][teammates[z].ground];
				ret = max(ret, total_score);
			}
		}
	}
	return ret;
}

int main() {
	read_input();
	process_data();
	// debug_print();
	printf("%d", solve());
	return 0;
}