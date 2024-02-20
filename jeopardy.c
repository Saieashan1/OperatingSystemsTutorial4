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

    // Initialize the game with questions
    initialize_game(questions);

    // Get player names and initialize
    for (int i = 0; i < NUM_PLAYERS; ++i)
    {
        printf("Enter the name of player %d: ", i + 1);
        fgets(buffer, MAX_PLAYER_NAME_LEN, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        initialize_player(&players[i], buffer);
    }

    while (1)
    {
        // Display remaining categories and question dollar values
        display_categories(questions);

        // Get the player who will pick the category and question
        printf("Enter the name of the player who will pick: ");
        fgets(buffer, MAX_PLAYER_NAME_LEN, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        // Validate and get the player index
        int playerIndex = get_player_index(players, NUM_PLAYERS, buffer);

        if (playerIndex != -1)
        {
            // Get category and dollar amount question
            char category[MAX_LEN];
            int value;

            printf("Enter the category: ");
            fgets(category, MAX_LEN, stdin);
            category[strcspn(category, "\n")] = '\0';

            printf("Enter the dollar amount for the question: ");
            scanf("%d", &value);
            getchar();  // Consume the newline character

            // Validate and get the question index
            int questionIndex = get_question_index(questions, category, value);

            if (questionIndex != -1 && !is_question_answered(questions, questionIndex))
            {
                // Display the question for the player to answer
                display_question(questions, category, value);

                // Get the player's answer
                printf("%s, enter your answer (start with 'what is' or 'who is'): ", players[playerIndex].name);
                fgets(buffer, MAX_QUESTION_LEN, stdin);
                buffer[strcspn(buffer, "\n")] = '\0';

                // Validate the answer
                if (valid_answer(questions, category, value, buffer))
                {
                    printf("Correct!\n");

                    // Update the player's score
                    update_score(&players[playerIndex], value);
                }
                else
                {
                    printf("Incorrect! The correct answer is: %s\n", get_answer(questions, questionIndex));
                }

                // Mark the question as answered
                mark_question_answered(questions, questionIndex);
            }
            else
            {
                printf("Invalid category or question amount. Please try again.\n");
            }
        }
        else
        {
            printf("Invalid player name. Please try again.\n");
        }

        // Check if the game has ended
        if (is_game_over(questions))
        {
            // Display results and exit the loop
            show_results(players, NUM_PLAYERS);
            break;
        }
    }

    return EXIT_SUCCESS;
}
