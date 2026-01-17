#include <stdio.h>
#include <stdlib.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX (int)(1e5)
const int MONDAY = 1,
		  TUESDAY = 2,
		  WEDNESDAY = 3,
		  THURSDAY = 4,
		  FRIDAY = 5,
		  SATURDAY = 6,
		  SUNDAY = 0;
const int WEEK = 7;

typedef struct Work {
	int deadline;
	int time;
} Work;

Work works[MAX_IDX];
int n;

int deadline_asc(const void* a, const void* b) {
	Work* x = (Work*)a;
	Work* y = (Work*)b;

	return x->deadline > y->deadline;
}

void read_input() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &works[i].deadline, &works[i].time);
	}
	qsort(works, n, sizeof(Work), deadline_asc);
	return;
}

int main() {
	read_input();

	int additional_work = 0, current_work = 0;
	bool is_invalid_state = true;

	for (int day = 1; day <= works[n - 1].deadline && current_work < n; ++day) {
		if ((day % WEEK) != SATURDAY && (day % WEEK) != SUNDAY) {
			works[current_work].time -= 1; // 오늘 일 처리
		}

		if (works[current_work].time == 0) { // 주어진 일을 모두 완료
			current_work += 1;
		}

		while (day == works[current_work].deadline) { // 끝내야 하는 일이 남음
			int need_to_work = works[current_work].time;
			int available_time = day - additional_work;

			if (need_to_work <= available_time) { // 시간외 작업을 했으면 처리할 수 있었음
				additional_work += need_to_work;
				current_work += 1;
			} else { // 모두 근무했었어도 처리할 수 없었음
				is_invalid_state = false;
				break;
			}
		}

		if (is_invalid_state == false) {
			break;
		}
	}

	printf("%d", is_invalid_state == false ? -1 : additional_work);
	return 0;
}