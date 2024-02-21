#ifndef QUESTIONS_H
#define QUESTIONS_H

#include <stdbool.h>

typedef struct {
    char category[50];
    char question[200];
    char answer[50];
    int value;
    int answered; // 0 for false, 1 for true
} Question;

void initialize_game(Question *questions);
void display_categories(Question *questions);
void display_question(Question *questions, char *category, int value);
bool valid_answer(Question *questions, char *category, int value, char *answer);
bool already_answered(Question *questions, char *category, int value);

#endif
