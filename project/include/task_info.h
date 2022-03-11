#ifndef PROJECT_INCLUDE_TASK_INFO_H_
#define PROJECT_INCLUDE_TASK_INFO_H_

#include "task_parser.h"

#define MAX_CHOICE_SIZE 10

typedef struct {
    char* number;
    char** description; // необходимо заменить на массив строк char* str[]
    char* priority;
    char* when;
} task_info;

typedef task_info* ptr_task;

int propose_action(); // готово
int make_choice(char *choice); // готово

ptr_task create_task(); // готово
int set_task(ptr_task task); // готово
int print_task(ptr_task task); // готово
int delete_task(ptr_task task); // готово
int delete_string(char** string); // не готово

#endif //  PROJECT_INCLUDE_TASK_INFO_H_
