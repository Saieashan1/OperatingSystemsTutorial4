#include "questions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initialize_game(Question *questions) {
    // Simple initialization example (replace with your own logic)
    for (int i = 0; i < 10; ++i) {
        sprintf(questions[i].category, "Category %d", i + 1);
        sprintf(questions[i].question, "What is the question for Category %d?", i + 1);
        sprintf(questions[i].answer, "Answer%d", i + 1);
        questions[i].value = (i + 1) * 100;
        questions[i].answered = 0; // Not answered
    }
}

void display_categories(Question *questions) {
    // Simple example to display categories and values
    printf("Categories and Values:\n");
    for (int i = 0; i < 10; ++i) {
        if (!questions[i].answered) {
            printf("%s - $%d\n", questions[i].category, questions[i].value);
        }
    }
}

void display_question(Question *questions, char *category, int value) {
    // Simple example to display a question
    int index = determine_question_index(questions, category, value);
    printf("Question for %s - $%d:\n", category, value);
    printf("%s\n", questions[index].question);
}

int determine_question_index(Question *questions, char *category, int value) {
    // Simple example to determine the index based on category and value
    for (int i = 0; i < 10; ++i) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            return i;
        }
    }
    return -1; // Not found
}

int valid_answer(Question *questions, char *category, int value, char *answer) {
    // Simple example to check if the answer is correct
    int index = determine_question_index(questions, category, value);
    return (index != -1 && strcmp(questions[index].answer, answer) == 0);
}

int already_answered(Question *questions, char *category, int value) {
    // Simple example to check if the question has already been answered
    int index = determine_question_index(questions, category, value);
    return (index != -1 && questions[index].answered == 1);
}
