#include <stdio.h>

#define MAX_LEN 100

char subject[MAX_LEN + 1];

/* 하나하나 switch해도 되고, 아무튼 계산식 만들어도 된다
A+: 4.3, A0: 4.0, A-: 3.7
B+: 3.3, B0: 3.0, B-: 2.7
C+: 2.3, C0: 2.0, C-: 1.7
D+: 1.3, D0: 1.0, D-: 0.7
F: 0.0
*/

float convert_grade(char* grade) {
	double ret = 0.0;

	// 앞글자 체크
	switch (grade[0]) {
		case 'A': {
			ret = 4.0;
			break;
		}
		case 'B': {
			ret = 3.0;
			break;
		}
		case 'C': {
			ret = 2.0;
			break;
		}
		case 'D': {
			ret = 1.0;
			break;
		}
		case 'F': {
			ret = 0.0;
			break;
		}
	}

	// 뒷글자 체크
	switch (grade[1]) {
		case '+': {
			ret += 0.3;
			break;
		}
		case '0': {
			ret += 0.0;
			break;
		}
		case '-': {
			ret -= 0.3;
			break;
		}
		case '\0': {
			ret += 0.0;
			break;
		}
	}

	return ret;
}

int main() {
	int n;
	scanf("%d", &n);

	// 입력 전 변수 설정
	float sum_of_credit = 0;
	float sum_of_grade = 0.0;

	// 입력
	for (int i = 0; i < n; ++i) {
		char grade[2 + 1];
		int credit;

		scanf("%s %d %s", subject, &credit, grade);
		float grade_score = convert_grade(grade);

		sum_of_grade += (grade_score * credit);
		sum_of_credit += credit;
	}

	// 계산 및 출력
	float ret = sum_of_grade / sum_of_credit;
	printf("%.2f", ret);
	return 0;
}