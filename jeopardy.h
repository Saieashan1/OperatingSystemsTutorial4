#ifndef JEOPARDY_H
#define JEOPARDY_H

#include "questions.h"
#include "players.h"

void tokenize(char *input, char **tokens);
void show_results(Player *players);

#endif
