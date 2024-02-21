#ifndef QUESTIONS_H
#define QUESTIONS_H

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
int determine_question_index(Question *questions, char *category, int value);
int valid_answer(Question *questions, char *category, int value, char *answer);
int already_answered(Question *questions, char *category, int value);

#endif

