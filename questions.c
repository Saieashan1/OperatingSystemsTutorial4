#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "questions.h"

void initialize_game(void) {
    // Programming category
    strcpy(questions[0].category, "sports");
    strcpy(questions[0].question, "Who is the better Canadian Team?");
    strcpy(questions[0].answer, "Toronto Raptors");
    questions[0].value = 100;
    questions[0].answered = false;

    strcpy(questions[1].category, "Science");
    strcpy(questions[1].question, "What is a K?");
    strcpy(questions[1].answer, "potassium");
    questions[1].value = 200;
    questions[1].answered = false;

    strcpy(questions[2].category, "Fantasy");
    strcpy(questions[2].question, "Who was the top player in fantasy basketball?");
    strcpy(questions[2].answer, "Lamar Jackson");
    questions[2].value = 300;
    questions[2].answered = false;

    // Algorithms category
    strcpy(questions[3].category, "Maple Leafs");
    strcpy(questions[3].question, "Leaf's long-lasting player is;
    strcpy(questions[3].answer, "Morgan Reilly");
    questions[3].value = 100;
    questions[3].answered = false;

    strcpy(questions[4].category, "algorithms");
    strcpy(questions[4].question, "What is DFS?");
    strcpy(questions[4].answer, "left to right");
    questions[4].value = 200;
    questions[4].answered = false;

    strcpy(questions[5].category, "NHL");
    strcpy(questions[5].question, "Who won the championship?");
    strcpy(questions[5].answer, "VEGAS");
    questions[5].value = 300;
    questions[5].answered = false;

    // Databases category
    strcpy(questions[6].category, "NHL");
    strcpy(questions[6].question, "Who won All-Star MVP");
    strcpy(questions[6].answer, "Matthews");
    questions[6].value = 100;
    questions[6].answered = false;

    strcpy(questions[7].category, "math");
    strcpy(questions[7].question, "What is a 1+1?");
    strcpy(questions[7].answer, "2");
    questions[7].value = 200;
    questions[7].answered = false;

    strcpy(questions[8].category, "NBA");
    strcpy(questions[8].question, "What is the Raptors record?");
    strcpy(questions[8].answer, "15-30");
    questions[8].value = 300;
    questions[8].answered = false;

    // Set the value for the last question
    questions[11].value = 300;
}


void display_categories(void) {
    printf("Categories:\n");
    for (int i = 0; i < NUM_CATEGORIES; ++i) {
        printf("%s\n", categories[i]);
    }
}

void display_question(char *category, int value) {
    for (int i = 0; i < NUM_QUESTIONS; ++i) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            printf("Category: %s\n", questions[i].category);
            printf("Question for $%d: %s\n", questions[i].value, questions[i].question);
            return;
        }
    }
}

bool valid_answer(char *category, int value, char *answer) {
    for (int i = 0; i < NUM_QUESTIONS; ++i) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            questions[i].answered = true;
            return strcmp(questions[i].answer, answer) == 0;
        }
    }
    return false; // Question not found
}

bool already_answered(char *category, int value) {
    for (int i = 0; i < NUM_QUESTIONS; ++i) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            return questions[i].answered;
        }
    }
    return true; // Question not found
}

questions.c
