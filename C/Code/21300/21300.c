main() {
	int sum = 0, x;
	for (int i = 0; i < 6; ++i) {
		scanf("%d", &x);
		sum += x;
	}
	printf("%d", sum * 5);
}