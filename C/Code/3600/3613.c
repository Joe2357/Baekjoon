#include <stdbool.h>
#include <stdio.h>

#define MAX_LEN 100

bool check_cpp(char* str) {
	if (('a' <= str[0] && str[0] <= 'z') == false) {
		return false;
	}
	int i;
	for (i = 1; str[i] != '\0'; ++i) {
		if ((('a' <= str[i] && str[i] <= 'z') || (str[i] == '_' && str[i - 1] != '_')) == false) {
			return false;
		}
	}
	return str[i - 1] != '_';
}

bool check_java(char* str) {
	if (('a' <= str[0] && str[0] <= 'z') == false) {
		return false;
	}
	for (int i = 1; str[i] != '\0'; ++i) {
		if ((('a' <= str[i] && str[i] <= 'z') || ('A' <= str[i] && str[i] <= 'Z')) == false) {
			return false;
		}
	}
	return true;
}

void print_as_java(char* str) {
	for (int i = 0; str[i] != '\0'; ++i) {
		if (str[i] == '_') {
			printf("%c", str[++i] + 'A' - 'a');
		} else {
			printf("%c", str[i]);
		}
	}
	return;
}

void print_as_cpp(char* str) {
	for (int i = 0; str[i] != '\0'; ++i) {
		if ('A' <= str[i] && str[i] <= 'Z') {
			str[i] -= 'A', str[i] += 'a';
			printf("_%c", str[i]);
		} else {
			printf("%c", str[i]);
		}
	}
	return;
}

int main() {
	char str[MAX_LEN + 1];
	scanf("%s", str);

	bool is_cpp_variable = check_cpp(str);
	bool is_java_variable = check_java(str);

	if (is_cpp_variable == true) {
		if (is_java_variable == true) {
			printf("%s", str);
		} else {
			print_as_java(str);
		}
	} else {
		if (is_java_variable == true) {
			print_as_cpp(str);
		} else {
			printf("Error!");
		}
	}
	return 0;
}