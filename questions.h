/* questions.h */

#ifndef QUESTIONS_H_
#define QUESTIONS_H_

#include <stdbool.h>

#define MAX_CATEGORIES 5  // Change to your desired value
#define NUM_DOLLAR_VALUES 5  // Change to your desired value
#define MAX_QUESTION_LEN 256

// Structure definition for a question
typedef struct {
    char category[MAX_QUESTION_LEN];
    char question[MAX_QUESTION_LEN];
    char answer[MAX_QUESTION_LEN];
    int value;
    bool answered;
} question;

// Function prototypes
extern void initialize_game(question questions[MAX_CATEGORIES][NUM_DOLLAR_VALUES]);
extern void display_categories(question questions[MAX_CATEGORIES][NUM_DOLLAR_VALUES]);
extern void display_question(question questions[MAX_CATEGORIES][NUM_DOLLAR_VALUES], char *category, int value);
extern bool valid_answer(question questions[MAX_CATEGORIES][NUM_DOLLAR_VALUES], char *category, int value, char *answer);
extern bool already_answered(question questions[MAX_CATEGORIES][NUM_DOLLAR_VALUES], char *category, int value);

#endif /* QUESTIONS_H_ */
