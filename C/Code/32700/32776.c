main() {
	int s_ab;
	scanf("%d", &s_ab);
	if (s_ab <= 240) {
		printf("high speed rail");
	} else {
		int m_a, f_ab, m_b;
		scanf("%d %d %d", &m_a, &f_ab, &m_b);
		if (m_a + f_ab + m_b < s_ab) {
			printf("flight");
		} else {
			printf("high speed rail");
		}
	}
	return 0;
}