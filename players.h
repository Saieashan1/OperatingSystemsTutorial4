/* players.h */

#ifndef PLAYERS_H_
#define PLAYERS_H_

#include <stdbool.h>

#define MAX_PLAYER_NAME_LEN 30
#define NUM_PLAYERS 4

typedef struct {
    char name[MAX_PLAYER_NAME_LEN];
    int score;
} player;

extern bool player_exists(player *players, char *name);
extern void update_score(player *players, char *name, int score);
extern void initialize_player(player *player, char *name);

#endif /* PLAYERS_H_ */
