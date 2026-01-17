main() {
	char str[100];

	while (1) {
		scanf("%s", str);

		if (str[0] == 'a') {
			printf("Panthera tigris\n");
		} else if (str[0] == 'f') {
			printf("Forsythia koreana\n");
		} else if (str[0] == 't') {
			printf("Pinus densiflora\n");
		} else {
			break;
		}
	}
	return 0;
}