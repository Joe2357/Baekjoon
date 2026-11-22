/**
 * BOJ 18789 814-2
 * Score :: 8189
 */

/**
 * My answer ::
  59417610657251
  30952307254658
  28625932738407
  14817694189239
  97036781450165
  65304250671648
  62192503798378
  44719834823594
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

char logDirectoryName[3][200] = {"C:\\Users\\user\\VisualStudioProjects\\EightOneFourProject\\log\\", "E:\\Project\\Visual Studio Code\\EightOneFourProject\\log\\", ""};
char inputDirectoryName[3][200] = {"C:\\Users\\user\\VisualStudioProjects\\EightOneFourProject\\input\\", "E:\\Project\\Visual Studio Code\\EightOneFourProject\\input\\", ""};
char DBDirectoryName[3][200] = {"C:\\Users\\user\\VisualStudioProjects\\EightOneFourProject\\DB\\", "E:\\Project\\Visual Studio Code\\EightOneFourProject\\DB\\", ""};
const int directoryOption = 0;
int DB_Number;

#define MAX_DB 50
#define MAX_SCORE 10000
#define SCORE_MAX_LEN 4
#define ROW_LEN 8
#define COL_LEN 14
const int NONE = -1;

const int MAX_DB_RENEW_THRESHOLD = 10;
const int MAX_SCORE_RENEW_THRESHOLD = 2;

const int MUTATE_BASE_VALUE = 1000;
const int MUTATE_DEFAULT_PROB = 15; /* 1.5% */

const int RANDOM_MATRIX_GENERATE_THRESHOLD = 1000;
const int RANDOM_MATRIX_GENERATE_PROB = 0; /* 0% */
const int EPOCH_LOG_LEN = 10;

#define MAX_DIR 8
typedef struct Position {
	int x, y;
} PS;
typedef struct ScoreNode {
	int d, x;
} SN;
PS dir[MAX_DIR] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

#define PERMUTATION_LEN 3628800
#define DIGIT 10
int permutation_value[PERMUTATION_LEN][10];
int permutation_idx;

#define min(a, b) (((a) > (b)) ? (b) : (a))

int getPermutatedNumber(int pi, int x, int digit) {
	int ret = 0;
	int current_digit = 1;
	for (int i = 0; i < digit + 1; ++i) {
		ret += (current_digit * permutation_value[pi][x % DIGIT]);
		x /= DIGIT, current_digit *= DIGIT;
	}
	return ret;
}

void getRandomMatrix(int grid[][COL_LEN]) {
	for (int i = 0; i < ROW_LEN; ++i) {
		for (int j = 0; j < COL_LEN; ++j) {
			grid[i][j] = rand() % DIGIT;
		}
	}
	return;
}

void dfs(bool score[][MAX_SCORE], int grid[][COL_LEN], int x, int y, int loop, int cur_score) {
	if (loop == SCORE_MAX_LEN) {
		return;
	}

	int new_score = DIGIT * cur_score + grid[x][y];
	score[SCORE_MAX_LEN][new_score] = score[loop][new_score] = true;

	for (int i = 0; i < MAX_DIR; ++i) {
		int new_x = x + dir[i].x;
		int new_y = y + dir[i].y;

		if (0 <= new_x && new_x < ROW_LEN && 0 <= new_y && new_y < COL_LEN) {
			dfs(score, grid, new_x, new_y, loop + 1, new_score);
		}
	}
	return;
}

int gradeGrid(int grid[][COL_LEN], bool enableSecondaryMetric) {
	bool score[SCORE_MAX_LEN + 1][MAX_SCORE] = {false};

	for (int i = 0; i < ROW_LEN; ++i) {
		for (int j = 0; j < COL_LEN; ++j) {
			dfs(score, grid, i, j, 0, 0);
		}
	}

	int s = 0;
	if (enableSecondaryMetric == false) {
		/* First Score */
		for (int i = 1; i < MAX_SCORE; ++i) {
			if (score[SCORE_MAX_LEN][i] == false) {
				break;
			}
			s = i;
		}
	} else {
		/* Second Score */
		for (int i = 1000; i < MAX_SCORE; ++i) {
			if (score[SCORE_MAX_LEN][i] == true) {
				++s;
			}
		}
	}

	return s;
}

void logGrid(int grid[][COL_LEN], int score, char* fl) {
	FILE* stream = fopen(fl, "w");

	for (int i = 0; i < ROW_LEN; ++i) {
		for (int j = 0; j < COL_LEN; ++j) {
			fprintf(stream, "%d", grid[i][j]);
		}
		fprintf(stream, "\n");
	}
	fprintf(stream, "\nscore : %d", score);
	fclose(stream);
	return;
}

void readGrid(int grid[][COL_LEN], int* score, char* fl) {
	FILE* stream = fopen(fl, "r");

	for (int i = 0; i < ROW_LEN; ++i) {
		for (int j = 0; j < COL_LEN; ++j) {
			fscanf(stream, "%1d", &grid[i][j]);
		}
	}

	int current_score = 0;
	char temp[100];
	fgets(temp, 100, stream);
	fgets(temp, 100, stream);
	fgets(temp, 100, stream);
	fclose(stream);

	for (int i = 8; temp[i] != '\0'; ++i) {
		current_score = current_score * DIGIT + temp[i] - '0';
	}

	*score = current_score;
	return;
}

void copyGrid(int target[][COL_LEN], int origin[][COL_LEN]) {
	for (int i = 0; i < ROW_LEN; ++i) {
		for (int j = 0; j < COL_LEN; ++j) {
			target[i][j] = origin[i][j];
		}
	}
	return;
}

int changeOneDigit(int my_grid[][COL_LEN], int ret_grid[][COL_LEN], int current_score, bool enableSecondaryMetric) {
	int new_score = current_score;
	int a = NONE, b = NONE, c = NONE;

	for (int i = 0; i < ROW_LEN; ++i) {
		for (int j = 0; j < COL_LEN; ++j) {
			int origin = my_grid[i][j];
			for (int k = 0; k < DIGIT; ++k) {
				my_grid[i][j] = k;

				int calc_score = gradeGrid(my_grid, enableSecondaryMetric);
				if (calc_score > new_score) {
					a = i, b = j, c = k;
					new_score = calc_score;
				}
			}
			my_grid[i][j] = origin;
		}
	}

	ret_grid[a][b] = c;
	return new_score;
}

int gradePermutatedGrid(int my_grid[][COL_LEN], int ret_grid[][COL_LEN], bool enableSecondaryMetric) {
	bool score[SCORE_MAX_LEN + 1][MAX_SCORE] = {false};
	int max_score = -1;
	int max_idx = -1;

	for (int i = 0; i < ROW_LEN; ++i) {
		for (int j = 0; j < COL_LEN; ++j) {
			dfs(score, my_grid, i, j, 0, 0);
		}
	}

	SN notFoundArray[MAX_SCORE * 2];
	int top = 0;
	int temp_digit = DIGIT;
	for (int i = 0; i < SCORE_MAX_LEN; ++i) {
		for (int j = 0; j < temp_digit; ++j) {
			if (score[i][j] == false) {
				notFoundArray[top++] = (SN){i, j};
			}
		}
		temp_digit *= DIGIT;
	}

	/* permutation */
	for (int a = 0; a < PERMUTATION_LEN; ++a) {
		if (a % (PERMUTATION_LEN / 10) == 0) {
			// printf("  [permutation Log] process %d0%% / 100%%\n", a / (PERMUTATION_LEN / 10));
		}

		bool sub_score[SCORE_MAX_LEN + 1][MAX_SCORE] = {false};
		for (int i = 0; i < top; ++i) {
			SN node = notFoundArray[i];
			int x = getPermutatedNumber(a, node.x, node.d);

			sub_score[node.d][x] = true;
			if (node.d == SCORE_MAX_LEN - 1) {
				sub_score[SCORE_MAX_LEN][x] = true;
			}
		}

		temp_digit = DIGIT;
		for (int i = 0; i < SCORE_MAX_LEN - 1; ++i) {
			for (int j = 0; j < temp_digit; ++j) {
				sub_score[SCORE_MAX_LEN][j] &= sub_score[i][j];
			}
			temp_digit *= DIGIT;
		}

		int s = 0;
		if (enableSecondaryMetric == false) {
			/* First Score */
			for (int i = 1; i < MAX_SCORE; ++i) {
				if (sub_score[SCORE_MAX_LEN][i] == true) {
					break;
				}
				s = i;
			}
		} else {
			/* Second Score */
			for (int i = 1000; i < MAX_SCORE; ++i) {
				if (sub_score[SCORE_MAX_LEN][i] == false) {
					++s;
				}
			}
		}

		/* compare results */
		if (s > max_score) {
			max_score = s;
			max_idx = a;
		}
	}

	/* copy result grid */
	for (int i = 0; i < ROW_LEN; ++i) {
		for (int j = 0; j < COL_LEN; ++j) {
			ret_grid[i][j] = permutation_value[max_idx][my_grid[i][j]];
		}
	}

	return max_score;
}

void mutate_default(int grid[][COL_LEN], int mutate_probability) {
	for (int i = 0; i < ROW_LEN; ++i) {
		for (int j = 0; j < COL_LEN; ++j) {
			int mutate_value = rand() % MUTATE_BASE_VALUE;

			if (mutate_value < mutate_probability) {
				int previous_value = grid[i][j];
				do {
					grid[i][j] = rand() % DIGIT;
				} while (grid[i][j] == previous_value);
				printf("    [mutate Log] mutated (%d, %d) : %d with value %d\n", i, j, previous_value, grid[i][j]);
			}
		}
	}
	return;
}

void mutate_number_of_grid(int grid[][COL_LEN], int cnt) {
	bool visit[ROW_LEN][COL_LEN + 1] = {false};
	for (int i = 0; i < cnt; ++i) {
		int rand_x, rand_y;
		do {
			rand_x = rand() % ROW_LEN, rand_y = rand() % COL_LEN;
		} while (visit[rand_x][rand_y] == true);
		visit[rand_x][rand_y] = true;

		int previous_value = grid[rand_x][rand_y];
		do {
			grid[rand_x][rand_y] = rand() % DIGIT;
		} while (grid[rand_x][rand_y] == previous_value);
	}
	return;
}

void backtrack_perm(int* arr, bool* visit, int idx) {
	if (idx == DIGIT) {
		for (int i = 0; i < DIGIT; ++i) {
			permutation_value[permutation_idx][i] = arr[i];
		}
		++permutation_idx;
		return;
	} else {
		for (int i = 0; i < DIGIT; ++i) {
			if (visit[i] == false) {
				visit[i] = true;
				arr[idx] = i;
				backtrack_perm(arr, visit, idx + 1);
				visit[i] = false;
			}
		}
		return;
	}
}

void permutation_init() {
	int arr[10] = {0};
	bool visit[10] = {false};
	backtrack_perm(arr, visit, 0);
	return;
}

int readDB(int DB[][ROW_LEN][COL_LEN], int* score_DB, int x, char* directoryName) {
	char fileName[300];
	int retval = 0;
	for (int i = 0; i < x; ++i) {
		sprintf(fileName, "%smatrix_%d.txt", directoryName, i);
		readGrid(DB[i], (score_DB + i), fileName);
		retval = score_DB[i];
	}
	return retval;
}

void insertDB(int DB[][ROW_LEN][COL_LEN], int* score_DB, int grid[][COL_LEN], int current_score, int* top) {
	/* same score check */
	for (int i = 0; i < *top; ++i) {
		if (current_score == score_DB[i]) {
			copyGrid(DB[i], grid);
			return;
		}
	}

	if (*top == MAX_DB) {
		copyGrid(DB[MAX_DB - 1], grid);
		score_DB[MAX_DB - 1] = current_score;
	} else {
		copyGrid(DB[*top], grid);
		score_DB[*top] = current_score;
		*top += 1;
	}

	int temp_grid[ROW_LEN][COL_LEN];
	int temp_score;
	for (int i = *top - 1; i > 0; --i) {
		if (score_DB[i] > score_DB[i - 1]) {
			copyGrid(temp_grid, DB[i - 1]);
			copyGrid(DB[i - 1], DB[i]);
			copyGrid(DB[i], temp_grid);

			temp_score = score_DB[i - 1];
			score_DB[i - 1] = score_DB[i];
			score_DB[i] = temp_score;
		} else {
			break;
		}
	}
	return;
}

void renewDB(int DB[][ROW_LEN][COL_LEN], int* score_DB, int cnt_DB, char* directoryName) {
	mkdir(directoryName);
	char fileName[300];

	for (int i = 0; i < cnt_DB; ++i) {
		sprintf(fileName, "%smatrix_%d.txt", directoryName, i);
		logGrid(DB[i], score_DB[i], fileName);
	}
	return;
}

void step1() {
	int max_score = -1;
	int max_idx = -1;

	int epoch;
	int threshold;

	printf("[System] Step 1 with epoch? :: ");
	scanf("%d", &epoch);
	printf("[System] Step 1 with threshold? :: ");
	scanf("%d", &threshold);

	int my_grid[ROW_LEN][COL_LEN];
	char fileName[300];

	for (int i = 0; i < epoch; ++i) {
		if (epoch >= 100) {
			if (i % (epoch / 100) == 0) {
				printf("  - process %d / 100%%\n", i / (epoch / 100));
			}
		} else {
			printf("  - process %d\n", i);
		}

		/* make grid */
		getRandomMatrix(my_grid);

		/* get score */
		int score = gradeGrid(my_grid, false);

		/* logging */
		if (score >= threshold) {
			sprintf(fileName, "%sStep1\\", logDirectoryName[directoryOption]);
			mkdir(fileName);
			sprintf(fileName, "%sStep1\\epoch_%d_score_%d.txt", logDirectoryName[directoryOption], i, score);
			logGrid(my_grid, score, fileName);
		}
		if (score > max_score) {
			max_score = score;
			max_idx = i;
		}
	}

	printf("max idx : %d, max score : %d\n", max_idx, max_score);
	return;
}

void step2() {
	int max_score;

	char fileName[300];
	char inputFileName[300];
	printf("[System] Step 2 with file name? :: ");
	scanf("%s", inputFileName);

	sprintf(fileName, "%s%s.txt", inputDirectoryName[directoryOption], inputFileName);
	int my_grid[ROW_LEN][COL_LEN];
	int changed_grid[ROW_LEN][COL_LEN];
	readGrid(my_grid, &max_score, fileName);
	copyGrid(changed_grid, my_grid);

	while (true) {
		int new_score = changeOneDigit(my_grid, changed_grid, max_score, false);

		if (new_score > max_score) {
			max_score = new_score;
		} else {
			break;
		}
		copyGrid(my_grid, changed_grid);
	}

	printf("max score : %d\n", max_score);
	sprintf(fileName, "%sStep2\\", logDirectoryName[directoryOption]);
	mkdir(fileName);
	sprintf(fileName, "%sStep2\\%s_result_%d.txt", logDirectoryName[directoryOption], inputFileName, max_score);
	logGrid(my_grid, max_score, fileName);
	return;
}

void step3() {
	int max_score = -1;
	int elapse_idx;

	char fileName[300];
	int program_idx;
	printf("[System] Step 3 with program index? :: ");
	scanf("%d", &program_idx);

	int my_grid[ROW_LEN][COL_LEN];
	int changed_grid[ROW_LEN][COL_LEN];
	getRandomMatrix(my_grid);
	copyGrid(changed_grid, my_grid);

	int epoch = 0;
	printf("[System] Step 3 with max epoch? :: ");
	scanf("%d", &epoch);

	sprintf(fileName, "%sStep3\\", logDirectoryName[directoryOption], program_idx);
	mkdir(fileName);
	sprintf(fileName, "%sStep3\\result_%d.txt", logDirectoryName[directoryOption], program_idx);

	int current_mutate_prob = MUTATE_DEFAULT_PROB;
	int previous_epoch_score = -1;
	for (elapse_idx = 0; elapse_idx < epoch; ++elapse_idx) {
		printf("[Log] Epoch %d :: \n", elapse_idx);
		int previous_score = -1;
		int new_score = -1;

		while (true) {
			previous_score = new_score;
			copyGrid(changed_grid, my_grid);

			/* one step */
			new_score = changeOneDigit(my_grid, changed_grid, new_score, false);
			copyGrid(my_grid, changed_grid);
			printf("  [epoch Log] New score : %d\n", new_score);

			if (new_score > max_score) {
				logGrid(my_grid, new_score, fileName);
				max_score = new_score;
			} else if (new_score == previous_score) {
				break;
			}
			previous_score = new_score;
		}

		/* default mutate */
		if (previous_epoch_score == new_score) {
			current_mutate_prob <<= 1;
		} else {
			current_mutate_prob = MUTATE_DEFAULT_PROB;
		}
		printf("  [mutate Log] mutate probability : %d\n", current_mutate_prob);
		mutate_default(my_grid, current_mutate_prob);

		previous_epoch_score = new_score;
	}

	printf("max score : %d\n", max_score);
	return;
}

void step4() {
	int max_score = -1;
	int elapse_idx;

	char fileName[300];
	int program_idx;
	printf("[System] Step 4 with program index? :: ");
	scanf("%d", &program_idx);

	int my_grid[ROW_LEN][COL_LEN];
	int changed_grid[ROW_LEN][COL_LEN];
	getRandomMatrix(my_grid);
	copyGrid(changed_grid, my_grid);

	int epoch = 0;
	printf("[System] Step 4 with max epoch? :: ");
	scanf("%d", &epoch);

	sprintf(fileName, "%sStep4\\", logDirectoryName[directoryOption], program_idx);
	mkdir(fileName);
	sprintf(fileName, "%sStep4\\result_%d.txt", logDirectoryName[directoryOption], program_idx);

	int current_mutate_prob = MUTATE_DEFAULT_PROB;
	int previous_epoch_score = -1;
	for (elapse_idx = 0; elapse_idx < epoch; ++elapse_idx) {
		printf("[Log] Epoch %d :: \n", elapse_idx);
		int previous_score = -1;
		int new_score = -1;

		while (true) {
			previous_score = new_score;
			copyGrid(changed_grid, my_grid);

			/* one step */
			new_score = changeOneDigit(my_grid, changed_grid, new_score, true);
			copyGrid(my_grid, changed_grid);
			printf("  [epoch Log] New score : %d\n", new_score);

			if (new_score > max_score) {
				logGrid(my_grid, new_score, fileName);
				max_score = new_score;
			} else if (new_score == previous_score) {
				break;
			}
			previous_score = new_score;
		}

		/* default mutate */
		if (previous_epoch_score == new_score) {
			current_mutate_prob <<= 1;
		} else {
			current_mutate_prob = MUTATE_DEFAULT_PROB;
		}
		printf("  [mutate Log] mutate probability : %d\n", current_mutate_prob);
		mutate_default(my_grid, current_mutate_prob);

		previous_epoch_score = new_score;
	}

	printf("max score : %d\n", max_score);
	return;
}

void step5() {
	int max_score = -1;
	int elapse_idx;

	char fileName[300];
	int program_idx;
	printf("[System] Step 5 with program index? :: ");
	scanf("%d", &program_idx);

	int my_grid[ROW_LEN][COL_LEN];
	int changed_grid[ROW_LEN][COL_LEN];
	getRandomMatrix(my_grid);
	copyGrid(changed_grid, my_grid);

	int epoch = 0;
	printf("[System] Step 5 with max epoch? :: ");
	scanf("%d", &epoch);

	sprintf(fileName, "%sStep5\\", logDirectoryName[directoryOption], program_idx);
	mkdir(fileName);
	sprintf(fileName, "%sStep5\\result_%d.txt", logDirectoryName[directoryOption], program_idx);

	int current_mutate_prob = MUTATE_DEFAULT_PROB;
	int previous_epoch_score = -1;
	for (elapse_idx = 0; elapse_idx < epoch; ++elapse_idx) {
		printf("[Log] Epoch %d :: \n", elapse_idx);
		int previous_score = -1;
		int new_score = -1;

		int previous_step4 = -1;
		int new_step4 = -1;

		/* Step 4 part */
		while (true) {
			previous_step4 = new_step4;
			copyGrid(changed_grid, my_grid);

			new_step4 = changeOneDigit(my_grid, changed_grid, new_step4, true);
			printf("  [epoch Log] Secondary score : %d\n", new_step4);

			if (new_step4 == previous_step4) {
				break;
			}
			copyGrid(my_grid, changed_grid);
			previous_step4 = new_step4;
		}

		/* Step 3 part */
		while (true) {
			previous_score = new_score;
			copyGrid(changed_grid, my_grid);

			/* one step */
			new_score = changeOneDigit(my_grid, changed_grid, new_score, false);
			copyGrid(my_grid, changed_grid);
			printf("  [epoch Log] New score : %d\n", new_score);

			if (new_score > max_score) {
				logGrid(my_grid, new_score, fileName);
				max_score = new_score;
			} else if (new_score == previous_score) {
				break;
			}
			previous_score = new_score;
		}

		/* default mutate */
		if (previous_epoch_score == new_score) {
			current_mutate_prob <<= 1;
		} else {
			current_mutate_prob = MUTATE_DEFAULT_PROB;
		}
		printf("  [mutate Log] mutate probability : %d\n", current_mutate_prob);
		mutate_default(my_grid, current_mutate_prob);

		previous_epoch_score = new_score;
	}

	printf("max score : %d\n", max_score);
	return;
}

void step6() {
	int temp;

	char fileName[300];
	char inputFileName[300];
	printf("[System] Step 6 with file name? :: ");
	scanf("%s", inputFileName);

	sprintf(fileName, "%s%s.txt", inputDirectoryName[directoryOption], inputFileName);
	int my_grid[ROW_LEN][COL_LEN];
	int changed_grid[ROW_LEN][COL_LEN];
	readGrid(my_grid, &temp, fileName);
	copyGrid(changed_grid, my_grid);

	int max_score = gradePermutatedGrid(my_grid, changed_grid, false);

	printf("max score : %d\n", max_score);
	sprintf(fileName, "%sStep6\\", logDirectoryName[directoryOption]);
	mkdir(fileName);
	sprintf(fileName, "%sStep6\\%s_result_%d.txt", logDirectoryName[directoryOption], inputFileName, max_score);
	logGrid(changed_grid, max_score, fileName);
	return;
}

void step7() {
	int max_score = -1;

	char fileName[300];
	int program_idx;
	printf("[System] Step 7 with program index? :: ");
	scanf("%d", &program_idx);

	int my_grid[ROW_LEN][COL_LEN];
	int changed_grid[ROW_LEN][COL_LEN];
	getRandomMatrix(my_grid);
	copyGrid(changed_grid, my_grid);

	int epoch = 0;
	printf("[System] Step 7 with max epoch? :: ");
	scanf("%d", &epoch);

	sprintf(fileName, "%sStep7\\", logDirectoryName[directoryOption], program_idx);
	mkdir(fileName);
	sprintf(fileName, "%sStep7\\result_%d.txt", logDirectoryName[directoryOption], program_idx);

	int current_mutate_prob = MUTATE_DEFAULT_PROB;
	int previous_epoch_score = -1;
	for (int elapse_idx = 0; elapse_idx < epoch; ++elapse_idx) {
		printf("[Log] Epoch %d :: \n", elapse_idx);
		printf("  [score Log] Current Max Score : %d\n", max_score);
		int previous_score = -1;
		int new_score = -1;

		/* secondary scoring */
		while (true) {
			previous_score = new_score;
			copyGrid(changed_grid, my_grid);

			/* one step */
			new_score = changeOneDigit(my_grid, changed_grid, new_score, true);
			copyGrid(my_grid, changed_grid);
			printf("  [epoch Log] second score : %d\n", new_score);

			if (new_score == previous_score) {
				break;
			}
			previous_score = new_score;
		}

		/* permutation */
		copyGrid(changed_grid, my_grid);
		new_score = gradePermutatedGrid(my_grid, changed_grid, false);
		copyGrid(my_grid, changed_grid);
		printf("  [epoch Log] Permutated score : %d\n", new_score);

		/* defalut score */
		previous_score = new_score = -1;
		while (true) {
			previous_score = new_score;
			copyGrid(changed_grid, my_grid);

			/* one step */
			new_score = changeOneDigit(my_grid, changed_grid, new_score, false);
			copyGrid(my_grid, changed_grid);
			printf("  [epoch Log] first score : %d\n", new_score);

			if (new_score > max_score) {
				logGrid(my_grid, new_score, fileName);
				max_score = new_score;
			} else if (new_score == previous_score) {
				break;
			}
			previous_score = new_score;
		}

		/* default mutate */
		if (previous_epoch_score == new_score) {
			current_mutate_prob <<= 1;
		} else {
			current_mutate_prob = MUTATE_DEFAULT_PROB;
		}
		printf("  [mutate Log] mutate probability : %d\n", current_mutate_prob);
		mutate_default(my_grid, current_mutate_prob);

		previous_epoch_score = new_score;
	}

	printf("max score : %d\n", max_score);
	return;
}

void step8() {
	int max_score = -1;
	char fileName[300];
	char directoryName[300];

	printf("[System] Program (DB) number? :: ");
	scanf("%d", &DB_Number);
	sprintf(directoryName, "%sDB%d\\", DBDirectoryName[directoryOption], DB_Number);
	mkdir(directoryName);

	int DB[MAX_DB][ROW_LEN][COL_LEN];
	int score_DB[MAX_DB];
	int cnt_DB = 0;
	printf("[System] How many matrix are in DB? :: ");
	scanf("%d", &cnt_DB);
	if (cnt_DB > 0) {
		readDB(DB, score_DB, cnt_DB, directoryName);
	}
	int min_score_DB;
	if (cnt_DB == MAX_DB) {
		min_score_DB = score_DB[MAX_DB - 1];
	} else {
		min_score_DB = NONE;
	}
	printf("[System] current min DB score : %d\n", min_score_DB);

	int my_grid[ROW_LEN][COL_LEN];
	int changed_grid[ROW_LEN][COL_LEN];
	int current_first_score = 0;
	int current_second_score = 0;

	for (int epoch = 0;; ++epoch) {
		// printf("[System Log] epoch %d\n", epoch);
		if (epoch % EPOCH_LOG_LEN == 0) {
			printf("[System Log] epoch %d\n", epoch);
		}

		/* get Matrix */
		if ((cnt_DB < MAX_DB) || (rand() % RANDOM_MATRIX_GENERATE_THRESHOLD < RANDOM_MATRIX_GENERATE_PROB)) {
			getRandomMatrix(my_grid);
			current_first_score = gradeGrid(my_grid, false);
			current_second_score = gradeGrid(my_grid, true);

			printf("  [System Log] new matrix created // score : %d\n", current_first_score);
		} else {
			int random_value = rand() % MAX_DB;
			sprintf(fileName, "%smatrix_%d.txt", directoryName, random_value);
			readGrid(my_grid, &current_first_score, fileName);
			current_second_score = gradeGrid(my_grid, true);

			// printf("  [System Log] Load matrix %d // score : %d\n", random_value, current_first_score);
		}
		copyGrid(changed_grid, my_grid);
		int origin_score = current_first_score;

		// train loop
		for (int renew_cnt_DB = 0; renew_cnt_DB < MAX_DB_RENEW_THRESHOLD; ++renew_cnt_DB) {
			/*
			for (int renew_cnt_score = 0; renew_cnt_score < MAX_SCORE_RENEW_THRESHOLD; ++renew_cnt_score) {
				int new_score = changeOneDigit(my_grid, changed_grid, current_second_score, true);

				if (new_score != current_second_score) {
					current_second_score = new_score;
					renew_cnt_score = 0;
				}
				copyGrid(my_grid, changed_grid);
			}
			printf("  [Epoch Result] matrix secondary score : %d\n", current_second_score);
		*/

			for (int renew_cnt_score = 0; renew_cnt_score < MAX_SCORE_RENEW_THRESHOLD; ++renew_cnt_score) {
				/* each train step */
				int new_score = changeOneDigit(my_grid, changed_grid, current_first_score, false);
				// printf("    [Training Loop] new score : %d\n", new_score);

				if (new_score != current_first_score) {
					current_first_score = new_score;
					renew_cnt_score = 0;
				}
				copyGrid(my_grid, changed_grid);
			}
			// printf("  [Epoch Result] matrix first score : %d\n", current_first_score);
			if (origin_score < current_first_score) {
				printf("  [System Log] New score found! matrix score : %d\n", current_first_score);
				origin_score = current_first_score;
			}

			/* save DB */
			if (current_first_score > min_score_DB) {
				insertDB(DB, score_DB, my_grid, current_first_score, &cnt_DB);
			}
			renewDB(DB, score_DB, cnt_DB, directoryName);
			if (cnt_DB == MAX_DB) {
				min_score_DB = score_DB[MAX_DB - 1];
			} else {
				min_score_DB = NONE;
			}

			/* mutate 2 values */
			mutate_number_of_grid(my_grid, 2);
			current_first_score = gradeGrid(my_grid, false);
			current_second_score = gradeGrid(my_grid, true);
			copyGrid(changed_grid, my_grid);
		}
	}
	return;
}

void util1() {
	int max_score;
	int elapse_idx;

	char fileName[300];
	char inputFileName[300];
	printf("[System] Util 1 with file name? :: ");
	scanf("%s", inputFileName);

	sprintf(fileName, "%s%s.txt", inputDirectoryName[directoryOption], inputFileName);
	int my_grid[ROW_LEN][COL_LEN];
	int greaterGrid[ROW_LEN][COL_LEN];
	readGrid(my_grid, &max_score, fileName);
	max_score = gradeGrid(my_grid, false);

	printf("correcting score : %d\n", max_score);
	sprintf(fileName, "%sUtil1\\", logDirectoryName[directoryOption]);
	mkdir(fileName);
	sprintf(fileName, "%sUtil1\\%s_result_%d.txt", logDirectoryName[directoryOption], inputFileName, max_score);
	logGrid(my_grid, max_score, fileName);
	return;
}

void util2() {
	char fileName[300];
	int matrix_cnt;
	printf("[System] Util 2 with matrix cnt? :: ");
	scanf("%d", &matrix_cnt);

	for (int i = 0; i < matrix_cnt; ++i) {
		int my_grid[ROW_LEN][COL_LEN];
		int temp_score;
		sprintf(fileName, "%smatrix_%d.txt", DBDirectoryName[directoryOption], i);
		readGrid(my_grid, &temp_score, fileName);

		int correct_score = gradeGrid(my_grid, false);
		printf("[System Log] matrix %d's score :: %d / %d\n", i, temp_score, correct_score);
	}
	return;
}

void util3() {
	char fileName[300];
	char directoryName[300];

	printf("[System] Program (DB) number? :: ");
	scanf("%d", &DB_Number);
	sprintf(directoryName, "%sDB%d\\", DBDirectoryName[directoryOption], DB_Number);
	mkdir(directoryName);

	int DB[MAX_DB][ROW_LEN][COL_LEN];
	int score_DB[MAX_DB];
	int cnt_DB = 0;
	printf("[System] How many matrix are in DB? :: ");
	scanf("%d", &cnt_DB);

	int grid_tmp1[ROW_LEN][COL_LEN], grid_tmp2[ROW_LEN][COL_LEN];
	int score_tmp1, score_tmp2;

	bool visit[MAX_DB + 1] = {false};
	for (int idx = 0; idx < cnt_DB; idx += 2) {
		int tmp1, tmp2;
		do {
			tmp1 = rand() % cnt_DB, tmp2 = rand() % cnt_DB;
		} while (visit[tmp1] == true || visit[tmp2] == true || tmp1 == tmp2);

		visit[tmp1] = true, visit[tmp2] = true;

		sprintf(fileName, "%smatrix_%d.txt", directoryName, tmp1);
		readGrid(grid_tmp1, &score_tmp1, fileName);
		sprintf(fileName, "%smatrix_%d.txt", directoryName, tmp2);
		readGrid(grid_tmp2, &score_tmp2, fileName);

		for (int i = 0; i < ROW_LEN; ++i) {
			for (int j = 0; j < COL_LEN / 2; ++j) {
				DB[idx][i][j] = grid_tmp1[i][j];
				DB[idx + 1][i][j] = grid_tmp2[i][j];
			}

			for (int j = COL_LEN / 2; j < COL_LEN; ++j) {
				DB[idx][i][j] = grid_tmp2[i][j];
				DB[idx + 1][i][j] = grid_tmp1[i][j];
			}
		}
		score_DB[idx] = gradeGrid(DB[idx], false);
		score_DB[idx + 1] = gradeGrid(DB[idx + 1], false);
	}

	/* sort */
	int temp_grid[ROW_LEN][COL_LEN];
	int temp_score;
	for (int i = cnt_DB - 1; i > 0; --i) {
		for (int j = 0; j < i; ++j) {
			if (score_DB[j] < score_DB[j + 1]) {
				copyGrid(temp_grid, DB[j]);
				copyGrid(DB[j], DB[j + 1]);
				copyGrid(DB[j + 1], temp_grid);

				temp_score = score_DB[j];
				score_DB[j] = score_DB[j + 1];
				score_DB[j + 1] = temp_score;
			}
		}
	}

	renewDB(DB, score_DB, cnt_DB, directoryName);
	return;
}

void util4() {
	char fileName[300];
	char directoryName[300];

	printf("[System] Program (DB) number? :: ");
	scanf("%d", &DB_Number);
	sprintf(directoryName, "%sDB%d\\", DBDirectoryName[directoryOption], DB_Number);
	mkdir(directoryName);

	int DB[MAX_DB][ROW_LEN][COL_LEN];
	int new_DB[MAX_DB][ROW_LEN][COL_LEN];
	int score_DB[MAX_DB];
	int cnt_DB = 0;
	printf("[System] How many matrix are in DB? :: ");
	scanf("%d", &cnt_DB);

	int my_grid[ROW_LEN][COL_LEN];
	int changed_grid[ROW_LEN][COL_LEN];
	int my_score;
	int new_score;

	for (int idx = 0; idx < cnt_DB; ++idx) {
		printf("[Step 1 Log] processing %d\n", idx);
		sprintf(fileName, "%smatrix_%d.txt", directoryName, idx);
		readGrid(DB[idx], &my_score, fileName);

		new_score = gradePermutatedGrid(DB[idx], changed_grid, false);

		copyGrid(new_DB[idx], changed_grid);
		score_DB[idx] = new_score;
	}

	/* sort */
	int temp_grid[ROW_LEN][COL_LEN];
	int temp_score;
	for (int i = cnt_DB - 1; i > 0; --i) {
		for (int j = 0; j < i; ++j) {
			if (score_DB[j] < score_DB[j + 1]) {
				copyGrid(temp_grid, new_DB[j]);
				copyGrid(new_DB[j], new_DB[j + 1]);
				copyGrid(new_DB[j + 1], temp_grid);

				temp_score = score_DB[j];
				score_DB[j] = score_DB[j + 1];
				score_DB[j + 1] = temp_score;
			}
		}
	}

	/* delete duplicated */
	for (int i = 0; i < cnt_DB - 1; ++i) {
		if (score_DB[i] == score_DB[i + 1]) {
			for (int j = i + 1; j < cnt_DB; ++j) {
				copyGrid(new_DB[j - 1], new_DB[j]);
				score_DB[j - 1] = score_DB[j];
			}
			--cnt_DB;
		}
	}

	sprintf(directoryName, "%sDB%d-1\\", DBDirectoryName[directoryOption], DB_Number);
	mkdir(directoryName);
	renewDB(new_DB, score_DB, cnt_DB, directoryName);

	for (int idx = 0; idx < cnt_DB; ++idx) {
		printf("[Step 2 Log] processing %d\n", idx);
		new_score = gradePermutatedGrid(DB[idx], changed_grid, true);
		copyGrid(my_grid, changed_grid);
		new_score = gradeGrid(my_grid, false);
		new_score = changeOneDigit(my_grid, changed_grid, new_score, false);

		copyGrid(new_DB[idx], changed_grid);
		score_DB[idx] = new_score;
	}

	/* sort */
	for (int i = cnt_DB - 1; i > 0; --i) {
		for (int j = 0; j < i; ++j) {
			if (score_DB[j] < score_DB[j + 1]) {
				copyGrid(temp_grid, new_DB[j]);
				copyGrid(new_DB[j], new_DB[j + 1]);
				copyGrid(new_DB[j + 1], temp_grid);

				temp_score = score_DB[j];
				score_DB[j] = score_DB[j + 1];
				score_DB[j + 1] = temp_score;
			}
		}
	}

	/* delete duplicated */
	for (int i = 0; i < cnt_DB - 1; ++i) {
		if (score_DB[i] == score_DB[i + 1]) {
			for (int j = i + 1; j < cnt_DB; ++j) {
				copyGrid(new_DB[j - 1], new_DB[j]);
				score_DB[j - 1] = score_DB[j];
			}
			--cnt_DB;
		}
	}

	sprintf(directoryName, "%sDB%d-2\\", DBDirectoryName[directoryOption], DB_Number);
	mkdir(directoryName);
	renewDB(new_DB, score_DB, cnt_DB, directoryName);
	return;
}

void util5() {
	char fileName[300];

	int DB[MAX_DB][ROW_LEN][COL_LEN];
	int score_DB[MAX_DB];
	int cnt_DB = 0;
	printf("[System] How many matrix are in input folder? :: ");
	scanf("%d", &cnt_DB);
	if (cnt_DB > 0) {
		readDB(DB, score_DB, cnt_DB, inputDirectoryName[directoryOption]);
	}

	int DB_Number;
	printf("[System] Which DB number? :: ");
	scanf("%d", &DB_Number);

	/* sort */
	int temp_grid[ROW_LEN][COL_LEN];
	int temp_score;
	for (int i = cnt_DB - 1; i > 0; --i) {
		for (int j = 0; j < i; ++j) {
			if (score_DB[j] < score_DB[j + 1]) {
				copyGrid(temp_grid, DB[j]);
				copyGrid(DB[j], DB[j + 1]);
				copyGrid(DB[j + 1], temp_grid);

				temp_score = score_DB[j];
				score_DB[j] = score_DB[j + 1];
				score_DB[j + 1] = temp_score;
			}
		}
	}

	/* remove duplicate */
	for (int i = 0; i < cnt_DB - 1; ++i) {
		if (score_DB[i] == score_DB[i + 1]) {
			/* pull all */
			for (int j = i + 1; j < cnt_DB; ++j) {
				copyGrid(DB[j - 1], DB[j]);
				score_DB[j - 1] = score_DB[j];
			}

			--cnt_DB;
		}
	}

	char directoryName[300];
	sprintf(directoryName, "%sDB%d\\", DBDirectoryName[directoryOption], DB_Number);
	mkdir(directoryName);
	renewDB(DB, score_DB, cnt_DB, directoryName);
	return;
}

void instruction() {
	printf(
		"===== [Instruction] =====\n"
		"- Step 1 : Random Selected Grid\n"
		"- Step 2 : Change One Digit\n"
		"- Step 3 : Change One Digit, default mutate\n"
		"- Step 4 : Change One Digit, default mutate, Secondary scoring\n"
		"- Step 5 : Step 4 + Step 3\n"
		"- Step 6 : Change Digits with Permutation\n"
		"- Step 7 : Step 2 + 3 + 4 + 5 + 6\n"
		"- Step 8 : Search multiple states\n"
		"\n"
		"===== [Utils] =====\n"
		"- Step 91 : Correcting Score (Secondary -> First)\n"
		"- Step 92 : Check All Score in DB\n"
		"- Step 93 : DB half paste\n"
		"- Step 94 : DB permutated\n"
		"- Step 95 : DB renew -> sort\n"
		"\n");

	printf("Choose mode : ");
	return;
}

int main() {
	srand((unsigned int)time(NULL));
	permutation_init();
	instruction();

	int input_step;

	scanf("%d", &input_step);
	switch (input_step) {
		case 1: { /* random generated */
			printf("[System] Choose Step 1\n");
			step1();
			break;
		}
		case 2: { /* change 1 digit */
			printf("[System] Choose Step 2\n");
			step2();
			break;
		}
		case 3: { /* change 1 digit (with default mutate) */
			printf("[System] Choose Step 3\n");
			step3();
			break;
		}
		case 4: { /* change 1 digit (with default mutate) & secondary scoring */
			printf("[System] Choose Step 4\n");
			step4();
			break;
		}
		case 5: { /* Step 3 + Step 4 */
			printf("[System] Choose Step 5\n");
			step5();
			break;
		}
		case 6: { /* 0123456789 */
			printf("[System] Choose Step 6\n");
			step6();
			break;
		}
		case 7: { /* All steps */
			printf("[System] Choose Step 7\n");
			step7();
			break;
		}
		case 8: { /* Search Multiple states */
			printf("[System] Choose Step 8\n");
			step8();
			break;
		}
		case 91: {
			printf("[System] Choose Util 1\n");
			util1();
			break;
		}
		case 92: {
			printf("[System] Choose Util 2\n");
			util2();
			break;
		}
		case 93: {
			printf("[System] Choose Util 3\n");
			util3();
			break;
		}
		case 94: {
			printf("[System] Choose Util 4\n");
			util4();
			break;
		}
		case 95: {
			printf("[System] Choose Util 5\n");
			util5();
			break;
		}
		default: {
			printf("[System] Wrong Step\n");
			break;
		}
	}

	return 0;
}
