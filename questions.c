/* questions.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "questions.h"
#include "categories.h"

static question questions[MAX_CATEGORIES][NUM_DOLLAR_VALUES];

void initialize_game(question *questions)
{
    // Implement initialization of questions array
}

void display_categories(question *questions)
{
    // Implement display of remaining categories and question dollar values
}

void display_question(question *questions, char *category, int value)
{
    // Implement display of a specific question
}

bool valid_answer(question *questions, char *category, int value, char *answer)
{
    // Implement answer validation logic
    return false;
}

bool already_answered(question *questions, char *category, int value)
{
    // Implement check if the question has already been answered
    return false;
}
