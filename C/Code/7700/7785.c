#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX (int)(1e6)
#define MAX_LEN 5
#define MAP_SIZE (int)(1e6 + 3)

typedef struct Node {
	char name[MAX_LEN + 1];
	struct Node* next;
} Node;

char name[MAX_LEN + 1], state[MAX_IDX + 1];
int n;
Node* hash_map[MAP_SIZE];

int get_hash(const char* str) {
	int hash = 0;
	for (int i = 0; str[i] != '\0'; ++i) {
		hash = (hash * 31 + str[i]) % MAP_SIZE;
	}
	return hash % MAP_SIZE;
}

void remove_from_map(const char* name) {
	int hash = get_hash(name);
	Node* curr = hash_map[hash];
	Node* prev = NULL;

	while (curr != NULL) {
		if (strcmp(curr->name, name) == 0) {
			if (prev == NULL) {
				hash_map[hash] = curr->next;
			} else {
				prev->next = curr->next;
			}
			free(curr);
			return;
		}
		prev = curr;
		curr = curr->next;
	}
	return;
}

void insert_to_map(const char* name) {
	int hash = get_hash(name);
	Node* new_node = (Node*)malloc(sizeof(Node));
	strcpy(new_node->name, name);
	new_node->next = hash_map[hash];
	hash_map[hash] = new_node;
	return;
}

void read_input() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s %s", name, state);

		remove_from_map(name);
		if (strcmp(state, "enter") == 0) {
			insert_to_map(name);
		}
	}
	return;
}

Node attendance[MAX_IDX];
int attendance_size = 0;

void make_array_for_attendance() {
	for (int i = 0; i < MAP_SIZE; ++i) {
		for (Node* curr = hash_map[i]; curr != NULL; curr = curr->next) {
			strcpy(attendance[attendance_size++].name, curr->name);
		}
	}
	return;
}

int string_compare(const char* a, const char* b) {
	return strcmp(b, a); // descending order
}

void print_attendance() {
	for (int i = 0; i < attendance_size; ++i) {
		printf("%s\n", attendance[i].name);
	}
	return;
}

int main() {
	read_input();
	make_array_for_attendance();
	qsort(attendance, attendance_size, sizeof(Node), string_compare);
	print_attendance();
	return 0;
}