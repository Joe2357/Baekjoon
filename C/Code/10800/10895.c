main() {
	int a, k;
	scanf("%d %d", &a, &k);
	if (k == 0) {
		printf("%d", a);
	} else if (a % 2 == 1) {
		printf("%d", a);
	} else {
		printf("1");
	}
	return 0;
}