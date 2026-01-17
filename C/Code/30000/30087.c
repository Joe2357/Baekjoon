#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_LEN 30
#define MAX_SEMINARS 7

typedef struct Seminar {
	char name[MAX_LEN + 1];
	char room[6];
} Seminar;

Seminar seminars[MAX_SEMINARS] = {
	{"Algorithm", "204"},
	{"DataAnalysis", "207"},
	{"ArtificialIntelligence", "302"},
	{"CyberSecurity", "B101"},
	{"Network", "303"},
	{"Startup", "501"},
	{"TestStrategy", "105"}};

bool isSameString(const char* str1, const char* str2) {
	for (int i = 0; str1[i] != '\0' && str2[i] != '\0'; ++i) {
		if (str1[i] != str2[i]) {
			return false;
		}
	}
	return true;
}

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		char query[MAX_LEN + 1];
		scanf("%s", query);
		for (int i = 0; i < MAX_SEMINARS; i++) {
			if (isSameString(seminars[i].name, query) == true) {
				printf("%s\n", seminars[i].room);
				break;
			}
		}
	}
	return 0;
}