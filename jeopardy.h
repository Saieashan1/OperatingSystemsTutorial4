/* jeopardy.h */

#ifndef JEOPARDY_H_
#define JEOPARDY_H_

#define MAX_LEN 256
#define NUM_PLAYERS 4

typedef struct {
    char name[MAX_LEN];
    int score;
} player;

extern void tokenize(char *input, char **tokens);
extern void show_results(player *players, int num_players);

#endif /* JEOPARDY_H_ */
