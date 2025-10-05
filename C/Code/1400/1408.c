#include <stdio.h>

typedef struct Day {
	int hour, minute, second;
} DAY;

int main() {
	DAY current, started;
	scanf("%d:%d:%d", &current.hour, &current.minute, &current.second);
	scanf("%d:%d:%d", &started.hour, &started.minute, &started.second);

	DAY result = (DAY){
		started.hour - current.hour,
		started.minute - current.minute,
		started.second - current.second};

	if (result.second < 0) {
		result.second += 60;
		result.minute -= 1;
	}
	if (result.minute < 0) {
		result.minute += 60;
		result.hour -= 1;
	}
	if (result.hour < 0) {
		result.hour += 24;
	}

	printf("%02d:%02d:%02d", result.hour, result.minute, result.second);
	return 0;
}