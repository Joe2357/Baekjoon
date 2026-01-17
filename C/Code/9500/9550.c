main(t) {
	scanf("%d", &t);
	while (t--) {
		int ret = 0;
		int n, k;
		scanf("%d %d", &n, &k);
		while (n--) {
			int a;
			scanf("%d", &a);
			ret += (a / k);
		}
		printf("%d\n", ret);
	}
}