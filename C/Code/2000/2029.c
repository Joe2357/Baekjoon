#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_MATCH 24
#define MAX_SQUARE 14

bool match[MAX_MATCH + 1];
bool need_match_to_make_square[MAX_SQUARE + 1][MAX_MATCH + 1];

void read_input() {
	char line[100];

	// line 1
	scanf("%s", line);
	match[0] = (line[1] == '-');
	match[1] = (line[4] == '-');
	match[2] = (line[7] == '-');

	// line 2
	scanf("%s", line);
	match[3] = (line[0] == '|');
	match[4] = (line[3] == '|');
	match[5] = (line[6] == '|');
	match[6] = (line[9] == '|');
	scanf("%s", line);

	// line 4
	scanf("%s", line);
	match[7] = (line[1] == '-');
	match[8] = (line[4] == '-');
	match[9] = (line[7] == '-');

	// line 5
	scanf("%s", line);
	match[10] = (line[0] == '|');
	match[11] = (line[3] == '|');
	match[12] = (line[6] == '|');
	match[13] = (line[9] == '|');
	scanf("%s", line);

	// line 6
	scanf("%s", line);
	match[14] = (line[1] == '-');
	match[15] = (line[4] == '-');
	match[16] = (line[7] == '-');

	// line 7
	scanf("%s", line);
	match[17] = (line[0] == '|');
	match[18] = (line[3] == '|');
	match[19] = (line[6] == '|');
	match[20] = (line[9] == '|');
	scanf("%s", line);

	// line 9
	scanf("%s", line);
	match[21] = (line[1] == '-');
	match[22] = (line[4] == '-');
	match[23] = (line[7] == '-');

	return;
}

void init() {
	// 1x1
	need_match_to_make_square[0][0] = true;
	need_match_to_make_square[0][3] = true;
	need_match_to_make_square[0][4] = true;
	need_match_to_make_square[0][7] = true;

	need_match_to_make_square[1][1] = true;
	need_match_to_make_square[1][4] = true;
	need_match_to_make_square[1][5] = true;
	need_match_to_make_square[1][8] = true;

	need_match_to_make_square[2][2] = true;
	need_match_to_make_square[2][5] = true;
	need_match_to_make_square[2][6] = true;
	need_match_to_make_square[2][9] = true;

	need_match_to_make_square[3][7] = true;
	need_match_to_make_square[3][10] = true;
	need_match_to_make_square[3][11] = true;
	need_match_to_make_square[3][14] = true;

	need_match_to_make_square[4][8] = true;
	need_match_to_make_square[4][11] = true;
	need_match_to_make_square[4][12] = true;
	need_match_to_make_square[4][15] = true;

	need_match_to_make_square[5][9] = true;
	need_match_to_make_square[5][12] = true;
	need_match_to_make_square[5][13] = true;
	need_match_to_make_square[5][16] = true;

	need_match_to_make_square[6][14] = true;
	need_match_to_make_square[6][17] = true;
	need_match_to_make_square[6][18] = true;
	need_match_to_make_square[6][21] = true;

	need_match_to_make_square[7][15] = true;
	need_match_to_make_square[7][18] = true;
	need_match_to_make_square[7][19] = true;
	need_match_to_make_square[7][22] = true;

	need_match_to_make_square[8][16] = true;
	need_match_to_make_square[8][19] = true;
	need_match_to_make_square[8][20] = true;
	need_match_to_make_square[8][23] = true;

	// 2x2
	need_match_to_make_square[9][0] = true;
	need_match_to_make_square[9][1] = true;
	need_match_to_make_square[9][3] = true;
	need_match_to_make_square[9][5] = true;
	need_match_to_make_square[9][10] = true;
	need_match_to_make_square[9][12] = true;
	need_match_to_make_square[9][14] = true;
	need_match_to_make_square[9][15] = true;

	need_match_to_make_square[10][1] = true;
	need_match_to_make_square[10][2] = true;
	need_match_to_make_square[10][4] = true;
	need_match_to_make_square[10][6] = true;
	need_match_to_make_square[10][11] = true;
	need_match_to_make_square[10][13] = true;
	need_match_to_make_square[10][15] = true;
	need_match_to_make_square[10][16] = true;

	need_match_to_make_square[11][7] = true;
	need_match_to_make_square[11][8] = true;
	need_match_to_make_square[11][10] = true;
	need_match_to_make_square[11][12] = true;
	need_match_to_make_square[11][17] = true;
	need_match_to_make_square[11][19] = true;
	need_match_to_make_square[11][21] = true;
	need_match_to_make_square[11][22] = true;

	need_match_to_make_square[12][8] = true;
	need_match_to_make_square[12][9] = true;
	need_match_to_make_square[12][11] = true;
	need_match_to_make_square[12][13] = true;
	need_match_to_make_square[12][18] = true;
	need_match_to_make_square[12][20] = true;
	need_match_to_make_square[12][22] = true;
	need_match_to_make_square[12][23] = true;

	// 3x3
	need_match_to_make_square[13][0] = true;
	need_match_to_make_square[13][1] = true;
	need_match_to_make_square[13][2] = true;
	need_match_to_make_square[13][3] = true;
	need_match_to_make_square[13][6] = true;
	need_match_to_make_square[13][10] = true;
	need_match_to_make_square[13][13] = true;
	need_match_to_make_square[13][17] = true;
	need_match_to_make_square[13][20] = true;
	need_match_to_make_square[13][21] = true;
	need_match_to_make_square[13][22] = true;
	need_match_to_make_square[13][23] = true;

	return;
}

int main() {
	read_input();
	init();

	int a = 0;
	for (int i = 0; i < MAX_MATCH; ++i) {
		a += (match[i] == false);
	}

	int b = 0;
	for (int i = 0; i < MAX_SQUARE; ++i) {
		bool can_make = true;
		for (int j = 0; j < MAX_MATCH; ++j) {
			if (need_match_to_make_square[i][j] == true && match[j] == false) {
				can_make = false;
				break;
			}
		}
		b += (can_make == true);
	}

	printf("%d %d", a, b);
	return 0;
}