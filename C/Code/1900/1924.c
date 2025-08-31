#include <stdio.h>

char day_of_the_week[7][4] = { // 요일 template
	"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
int day_per_month[13] = { // 월 -> 일 변환기
	0, 31, 28, 31, 30, 31, 30,
	31, 31, 30, 31, 30, 31};

int main() {
	int month, day;
	scanf("%d %d", &month, &day);

	// 1월 1일부터 "총 며칠" 지났는지 계산
	for (month; month > 1; --month) {
		day += day_per_month[month - 1];
	}

	// 결과 출력
	printf("%s", day_of_the_week[day % 7]);
	return 0;
}