#ifndef PROJECT_INCLUDE_TASK_INFO_H_
#define PROJECT_INCLUDE_TASK_INFO_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "task_data.h"

#define MAX_STR_SIZE 1024
#define MAX_CHOICE_SIZE 10

#define SUCCESS 0
#define ERROR -1
#define INCORRECT 1

typedef struct {
    size_t* number;
    char* description; // необходимо заменить на массив строк char* str[]
    size_t* priority;
    double* when;
} task_info;

typedef task_info* ptr_task;

int propose_action(); // готово
int make_choice(char *choice); // готово

ptr_task create_task(); // готово
int set_task(ptr_task task); // готово
int print_task(ptr_task task); // готово
int delete_task(ptr_task task); // готово

#endif //  PROJECT_INCLUDE_TASK_INFO_H_
