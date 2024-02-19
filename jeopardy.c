/* jeopardy.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jeopardy.h"
#include "questions.h"
#include "players.h"

int main()
{
    player players[NUM_PLAYERS];
    char buffer[MAX_QUESTION_LEN];

    initialize_game(questions);

    for (int i = 0; i < NUM_PLAYERS; ++i)
    {
        printf("Enter the name of player %d: ", i + 1);
        fgets(buffer, MAX_PLAYER_NAME_LEN, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        initialize_player(&players[i], buffer);
    }

    while (1)
    {
        display_categories(questions);

        // Implement game logic here

        // Check if the game has ended
        if (is_game_over(questions))
        {
            show_results(players);
            break;
        }
    }

    return EXIT_SUCCESS;
}
