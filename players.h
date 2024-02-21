#ifndef PLAYERS_H
#define PLAYERS_H

#include <stdbool.h>

typedef struct {
    char name[50];
    int score;
} Player;

bool player_exists(Player *players, char *name);
void update_score(Player *players, char *name, int score);

#endif
