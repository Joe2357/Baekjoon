main() {
	int n;
	char str[10001];
	scanf("%d %s", &n, str);

	int score = 0, bonus = 0;
	for (int i = 0; i < n; ++i) {
		if (str[i] == 'O') {
			score += (i + 1);
			score += (bonus++);
		} else {
			bonus = 0;
		}
	}

	printf("%d", score);
	return 0;
}