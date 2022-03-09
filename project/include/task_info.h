#ifndef PROJECT_INCLUDE_TASK_INFO_H_
#define PROJECT_INCLUDE_TASK_INFO_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <time.h>

#define MAX_STR_SIZE 1024
#define MAX_CHOICE_SIZE 10
typedef enum {
    SUCCESS,
    FAILURE
} response;

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

typedef task_info* ptr_task;

void propose_action();
int make_choice(char *choice);

ptr_task create_task_list(ptr_task task_list);
ptr_task sort_task_list();
void print_task_list(ptr_task task_list);
void delete_task_list(ptr_task task_list);

ptr_task create_task();
int set_task(ptr_task cur_task);
int add_task(ptr_task task_list, ptr_task cur_task, size_t size);
void print_task(ptr_task cur_task);
void delete_task(ptr_task task);

#endif PROJECT_INCLUDE_TASK_INFO_H_  //  PROJECT_INCLUDE_TASK_INFO_H_