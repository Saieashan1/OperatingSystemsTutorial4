/* questions.h */

#ifndef QUESTIONS_H_
#define QUESTIONS_H_

#include <stdbool.h>

#define MAX_QUESTION_LEN 256
#define NUM_DOLLAR_VALUES 5

typedef struct {
    char category[MAX_CATEGORY_NAME_LEN];
    char question[MAX_QUESTION_LEN];
    char answer[MAX_QUESTION_LEN];
    int value;
    bool answered;
} question;

extern void initialize_game(question *questions);
extern void display_categories(question *questions);
extern void display_question(question *questions, char *category, int value);
extern bool valid_answer(question *questions, char *category, int value, char *answer);
extern bool already_answered(question *questions, char *category, int value);

#endif /* QUESTIONS_H_ */
