#ifndef player_h
#define player_h

#include <stdint.h>

#include "token.h"
#include "hero.h"

struct player
{
	char* name;
	uint8_t is_ai;
	uint8_t number;
	uint8_t team;
	char* color; // This should be a pointer to a real color like rgb.
	struct hero* hero;
	struct token token;
	struct token special_token;
	uint8_t special_token_amount;
	uint8_t special_skill_aviable;
	uint8_t points;
};

void init_player(struct player* a_player, char* name, uint8_t is_ai, uint8_t number, uint8_t team, char* color,
				struct hero* hero_played);

void delete_player(struct player a_player);

#endif
