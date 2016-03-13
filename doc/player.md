#**Player**

---
struct player
{
	char* name;
	uint8_t is_ai;
	uint8_t number;
	uint8_t team;
	cc_color_t color;
	struct hero* hero;
	struct token token;
	struct token special_token;
	uint8_t special_token_amount;
	uint8_t is_special_skill_available;
	uint8_t points;
};

---
The data structure player represent a player taking part in a game.
A player have:
* a name
* an indicator to tell if it is an ai
* a number to indicate in which order he/she plays
* the number of his/her team
* a color to differentiate his/her token
* a reference to the hero he/she is playing
* the standard token he/she can play
* the special token he/she can play specified by his/her hero
* the amount of special token aviable
* an indicator to tell if the player can use the special skill of his/her hero
* his/her points in the current game

Human players and computer players use the same structure.
Players are created before the start of the game, from informations given by the user in the lobby phase.
Players can't have the same name. They can have the same color only if they are in the same team.
There is  alot of dependencies between the players, the board and the game conditions (points to win, time to play), elements of data in structure and/or algorithm must prevent users to create incompatible games.
The order of players is determined randomly after the lobby phase.

---
####void init_player(struct player* _player_, char* _name_, uint8_t _is\_ai_,
					 uint8_t _team_, color _color_, struct hero* _hero\_played_):
Initialize a player structure with the values given as parameters.
The _number_ property of the player is not initialized, it is decided once a game involving this player start.
The initialization of the _name_ property use the malloc function.
The initialization _special\_token_ and _special\_token\_amount_ properties depends on the _hero\_played_ parameter.
The _is\_special\_skill\_available_ and _points_ properties are both initialized at zero.
Prerequisite:
* _player_ must be a pointer to an uninitialized player structure
* _name_ must be less than 256 character long
* _hero\_played_ must be an initialized hero
* _color_ have to be a valid color (according to the colors defined by the enumeration in console_color.h)

**Once you finished using the player initialized by this function, use the delete_player function on it.**

---
####void delete_player(struct player _player_):
Free memory taken by the malloc-ed properties of _player_
Prerequisite:
* _player_ need to be an initialized player structure