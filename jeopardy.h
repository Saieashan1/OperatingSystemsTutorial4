/* jeopardy.h */

#ifndef JEOPARDY_H_
#define JEOPARDY_H_

#include "questions.h"
#include "players.h"

#define NUM_PLAYERS 4
#define MAX_PLAYER_NAME_LEN 256
#define MAX_QUESTION_LEN 256
#define MAX_LEN 256

// Function declarations
extern void initialize_game(question *questions);
extern void display_categories(question *questions);
extern void display_question(question *questions, char *category, int value);
extern int get_player_index(player *players, int num_players, char *name);
extern int get_question_index(question *questions, char *category, int value);
extern int is_question_answered(question *questions, int index);
extern void mark_question_answered(question *questions, int index);
extern int is_game_over(question *questions);
extern void show_results(player *players, int num_players);

#endif /* JEOPARDY_H_ */
