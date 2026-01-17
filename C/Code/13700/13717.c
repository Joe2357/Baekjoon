#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_POKEMON 70
#define MAX_LEN 20
const int EARN_CANDY_PER_EVOLUTION = 2;

typedef struct Pokemon {
	char name[MAX_LEN + 1];
	int need_candy, have_candy;
	int evolution_cnt;
} Pokemon;

Pokemon pokemons[MAX_POKEMON];
int n;

int main() {
	scanf("%d", &n);

	int ret = 0;
	int evolution_cnt = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%s %d %d", pokemons[i].name, &pokemons[i].need_candy, &pokemons[i].have_candy);
		while (pokemons[i].have_candy >= pokemons[i].need_candy) {
			pokemons[i].have_candy -= pokemons[i].need_candy;
			pokemons[i].have_candy += EARN_CANDY_PER_EVOLUTION;
			pokemons[i].evolution_cnt += 1;
		}
		evolution_cnt += pokemons[i].evolution_cnt;

		if (pokemons[i].evolution_cnt > pokemons[ret].evolution_cnt) {
			ret = i;
		}
	}

	printf("%d\n%s", evolution_cnt, pokemons[ret].name);
	return 0;
}