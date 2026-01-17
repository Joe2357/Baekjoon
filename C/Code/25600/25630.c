main() {
	int n;
	scanf("%d", &n);
	char str[101];
	scanf("%s", str);

	int ret = 0;
	for (int i = 0, j = n - 1; i < j; ++i, --j)
		ret += (str[i] != str[j]);
	printf("%d", ret);
}