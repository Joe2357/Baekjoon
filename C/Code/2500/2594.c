#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef struct Time {
	int hour;
	int minute;
} Time;

#define MAX_HOUR 24
#define HOUR_TO_MINUTE 60
const int TERM = 10;

bool has_schedule[MAX_HOUR * HOUR_TO_MINUTE + 1];
Time open = {10, 0}, close = {22, 0}, end_of_day = {MAX_HOUR, 0};

#define max(a, b) ((a) > (b) ? (a) : (b))

int convert_to_minute(Time t) {
	return t.hour * HOUR_TO_MINUTE + t.minute;
}

void init() {
	for (int i = 0; i < convert_to_minute(end_of_day); ++i) {
		has_schedule[i] = false;
	}
	for (int i = 0; i < convert_to_minute(open); ++i) {
		has_schedule[i] = true;
	}
	for (int i = convert_to_minute(close); i < convert_to_minute(end_of_day); ++i) {
		has_schedule[i] = true;
	}
	return;
}

int main() {
	init();

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		Time start, end;
		scanf("%2d%2d %2d%2d", &start.hour, &start.minute, &end.hour, &end.minute);
		for (int j = convert_to_minute(start) - TERM; j < convert_to_minute(end) + TERM; ++j) {
			has_schedule[j] = true;
		}
	}

	int max_break_time = 0;
	int current_break_time = 0;
	for (int i = 0; i < convert_to_minute(end_of_day); ++i) {
		if (has_schedule[i] == false) {
			current_break_time += 1;
		} else {
			max_break_time = max(max_break_time, current_break_time);
			current_break_time = 0;
		}
	}
	max_break_time = max(max_break_time, current_break_time);

	printf("%d", max_break_time);
	return 0;
}
