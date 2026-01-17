#include <stdio.h>

const int BAK_PER_MADI = 4;
const int SECOND_PER_MINUTE = 60;

int main() {
	int n, k;
	double bpm;
	scanf("%d %lf %d", &n, &bpm, &k);

	double ans = 0.0;
	int current_idx = 1;
	while (k--) {
		int m;
		double new_bpm;
		scanf("%d %lf", &m, &new_bpm);

		ans += ((m - current_idx) * BAK_PER_MADI / bpm);
		current_idx = m;
		bpm = new_bpm;
	}
	ans += ((n + 1 - current_idx) * BAK_PER_MADI / bpm);
	printf("%.12lf", ans * SECOND_PER_MINUTE);
	return 0;
}