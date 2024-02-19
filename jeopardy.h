/* jeopardy.h */

#ifndef JEOPARDY_H_
#define JEOPARDY_H_

#include "questions.h"
#include "players.h"

extern void tokenize(char *input, char **tokens);
extern void show_results(player *players);

#endif /* JEOPARDY_H_ */
