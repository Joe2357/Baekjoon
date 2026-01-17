main(l, h) {
	scanf("%d%d", &l, &h);
	printf("%d", h % 2 && (l + 1) % 2 ? h - 1 : h);
}