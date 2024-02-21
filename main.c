#include <stdio.h>
#include <string.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

int main() {
    // Define necessary variables
    Player players[4];  // Assuming 4 players
    Question questions[10];

    // Initialize players and questions
    initialize_game(questions);

    // Get player names
    for (int i = 0; i < 4; ++i) {
        printf("Enter the name of Player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }

    // Start the game
    for (int round = 1; round <= 5; ++round) {
        printf("\nRound %d\n", round);

        // Display categories and questions
        display_categories(questions);

        // Allow each player to choose a question
        for (int i = 0; i < 4; ++i) {
            printf("\n%s, it's your turn!\n", players[i].name);

            // Get the category and dollar amount
            char category[50];
            int value;

            printf("Enter the category: ");
            scanf("%s", category);

            printf("Enter the dollar amount: ");
            scanf("%d", &value);

            // Display the question
            display_question(questions, category, value);

            // Get and process the player's answer
            char answer[50];
            printf("Your answer (Who will win the NBA championship?): ");
            scanf("%s", answer);

            // Check if the answer is correct
            if (valid_answer(questions, category, value, answer)) {
                printf("Correct!\n");
                players[i].score += value;
            } else {
              int questionIndex = determine_question_index(questions, category, value); // Replace with your logic
              printf("Incorrect! The correct answer is %s.\n", questions[questionIndex].answer);

            }

            // Mark the question as answered
            int questionIndex = determine_question_index(questions, category, value); // Replace with your logic
questions[questionIndex].answered = 1;

            // Display remaining categories and questions
            display_categories(questions);
        }
    }

    // Display final results
    show_results(players);

    return 0;
}
