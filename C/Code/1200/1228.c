#include <stdio.h>
#include <string.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_COUNTRY 200
#define COUNTRY_MAX_LEN (100 + 1)
#define surplus 10000
const long long INF = 987654321987654321;

const int ROOT = 0;
const int NONE = -1;

typedef struct TreeNode {
	char country_name[COUNTRY_MAX_LEN];
	bool isRoot;
	long long conquer_day;
	bool dependency[MAX_COUNTRY + 2];
	int dependency_cnt;
} TN;

char input[MAX_COUNTRY][MAX_COUNTRY * COUNTRY_MAX_LEN + surplus];
TN country[MAX_COUNTRY + 1];
int n, m;

long long dp[MAX_COUNTRY + 1][MAX_COUNTRY + 1];

#define min(a, b) (((a) > (b)) ? (b) : (a))

void read_input() {
	scanf("%d %d\n", &n, &m);
	for (int i = 0; i < n; ++i) {
		gets(input[i]);
	}
	return;
}

int find_country(char* buf) {
	for (int i = 1; i <= n; ++i) {
		if (strcmp(buf, country[i].country_name) == 0) {
			return i;
		}
	}
	return NONE;
}

void process_input() {
	char buf[COUNTRY_MAX_LEN];
	int i, l;

	/* country info */
	for (int idx = 0; idx < n; ++idx) {
		/* country name */
		for (i = 0; input[idx][i] != ' '; ++i) {
			buf[i] = input[idx][i];
		}
		buf[i] = '\0';
		strcpy(country[idx + 1].country_name, buf);

		/* temporally root */
		country[idx + 1].isRoot = true;

		/* country conquer day */
		country[idx + 1].conquer_day = 0;
		for (++i; input[idx][i] != '\0' && input[idx][i] != ' '; ++i) {
			country[idx + 1].conquer_day = country[idx + 1].conquer_day * 10 + (input[idx][i] - '0');
		}

		/* temporally used */
		country[idx + 1].dependency_cnt = i;
	}

	/* dependency country init */
	for (int idx = 0; idx < n; ++idx) {
		i = country[idx + 1].dependency_cnt;
		country[idx + 1].dependency_cnt = NONE;

		for (int temp = 0; input[idx][i] != '\0'; ++temp) {
			for (++i, l = 0; input[idx][i] != '\0' && input[idx][i] != ' '; ++i, ++l) {
				buf[l] = input[idx][i];
			}
			buf[l] = '\0';

			int find_idx = find_country(buf);
			country[idx + 1].dependency[find_idx] = true;
			country[find_idx].isRoot = false;
		}
	}

	/* make system root (0) */
	strcpy(country[ROOT].country_name, "SYSTEM_ROOT");
	country[ROOT].conquer_day = INF + 1;
	country[ROOT].dependency_cnt = n;
	for (int i = 1; i <= n; ++i) {
		if (country[i].isRoot == true) {
			country[ROOT].dependency[i] = true;
		}
	}

	return;
}

int count_dependency(int idx) {
	if (country[idx].dependency_cnt != NONE) {
		return country[idx].dependency_cnt;
	}

	int retval = 1; // itself
	for (int i = 1; i <= n; ++i) {
		if (country[idx].dependency[i] == true) {
			retval += count_dependency(i);
		}
	}
	return country[idx].dependency_cnt = retval;
}

void init() {
	read_input();
	process_input();

	for (int i = 1; i <= n; ++i) {
		country[i].dependency_cnt = count_dependency(i);
	}
	for (int i = 0; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			dp[i][j] = INF;
		}
	}

	return;
}

void print_tree() {
	for (int i = 1; i <= n; ++i) {
		printf("country %d : %s\n", i, country[i].country_name);
		printf("  isRoot : %s\n", (country[i].isRoot == true) ? "true" : "false");
		printf("  dependency count : %d\n    ", country[i].dependency_cnt);

		for (int j = 1; j <= n; ++j) {
			printf("%d", country[i].dependency[j]);
		}
		printf("\n");
	}
	return;
}

void print_dp() {
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			printf("%5lld ", dp[i][j]);
		}
		printf("\n");
	}
	return;
}

void solve(int root) {
	/* add informantion if we conquer this root */
	dp[root][country[root].dependency_cnt] = country[root].conquer_day;

	/* conquer sub-tree */
	for (int i = 1; i <= n; ++i) {
		if (country[root].dependency[i] == true) {
			solve(i);

			for (int j = country[root].dependency_cnt; j > 0; --j) {
				for (int t = j; t > 0; --t) {
					dp[root][j] = min(dp[root][j], dp[root][j - t] + dp[i][t]);
				}
			}
		}
	}

	return;
}

int main() {
	init();

	// print_tree();

	/* solving */
	solve(ROOT);

	// print_dp();

	/* print results */
	long long result = INF + 1;
	for (int i = m; i <= n; ++i) {
		result = min(result, dp[ROOT][i]);
	}
	printf("%lld", result);

	return 0;
}