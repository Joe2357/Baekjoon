main() {
	char str[10];
	int ret = 0;
	for (int i = 0; i < 8; ++i) {
		scanf("%s", str);

		for (int j = 0; j < 8; ++j) {
			switch (str[j]) {
				case 'p': {
					ret -= 1;
					break;
				}
				case 'P': {
					ret += 1;
					break;
				}
				case 'n': {
					ret -= 3;
					break;
				}
				case 'N': {
					ret += 3;
					break;
				}
				case 'b': {
					ret -= 3;
					break;
				}
				case 'B': {
					ret += 3;
					break;
				}
				case 'r': {
					ret -= 5;
					break;
				}
				case 'R': {
					ret += 5;
					break;
				}
				case 'q': {
					ret -= 9;
					break;
				}
				case 'Q': {
					ret += 9;
					break;
				}
			}
		}
	}
	printf("%d", ret);
	return 0;
}