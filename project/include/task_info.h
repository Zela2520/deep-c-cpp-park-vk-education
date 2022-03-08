#ifndef PROJECT_INCLUDE_TASK_INFO_
#define PROJECT_INCLUDE_TASK_INFO_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#define MAX_STR_SIZE 10000


//typedef enum {
//    LOWEST,
//    MEDIUM,
//    TOP,
//    URGENT_TASK
//} priority;

typedef struct {
    size_t* number;
    char* description;
    size_t* priority;
    double* when;
} task_info;

typedef task_info* pointer_task_lists;

void propose_action();

void create_task_lists(pointer_task_lists current_task_lists);
void delete_task_lists(pointer_task_lists current_task_lists);

pointer_task_lists create_task();
int set_task(pointer_task_lists current_task);
void print_task(pointer_task_lists current_task);
void delete_task(pointer_task_lists task);

void free_all();


#endif PROJECT_INCLUDE_TASK_INFO_ //  PROJECT_INCLUDE_TASK_INFO_