#include <stdio.h>

int main(t, temp) {
	char str[101], grade[3];
	float result = 0, point = 0;
	for (scanf("%d", &t); t; t--) {
		scanf("%s %d %s", str, &temp, grade);
		point += temp;                          // all points
		float gradeTemp = 0;                    // grade value
		if (grade[0] != 'F') {
			gradeTemp = 'E' - grade[0];
			switch (grade[1]) {
				case '+':
					gradeTemp += 0.3;
					break;
				case '-':
					gradeTemp -= 0.3;
					break;
			}
			result += gradeTemp * temp;         // variable for calculating average
		}
	}
	printf("%.2f", result / point);
	return 0;
}