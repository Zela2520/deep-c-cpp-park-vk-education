#ifndef PROJECT_INCLUDE_TASK_INFO_H_
#define PROJECT_INCLUDE_TASK_INFO_H_

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR_SIZE 1024

#define MAX_CHOICE_SIZE 10

#define ERROR -1
#define SUCCESS 0
#define INCORRECT 1

#define FIELDS_NAMES 4
#define NUMBER 4
#define DESCRIPTION 3
#define PRIORITY 2
#define WHEN 1

#define MAX_PRIORITY_SIZE 1
#define MAX_NUMBER_SIZE 2
#define MAX_DATA_SIZE 12

#define PARTS_NUMBERS 3

typedef enum {
    FIRST_PART = 0,
    SECOND_PART = 1,
    THIRD_PART = 2
} data_parts;

typedef enum {
    FIRST_DIVIDER = 2,
    SECOND_DIVIDER = 5
} data_points;

typedef struct {
    int number;
    int month;
    int year;
} Data;

typedef struct {
    char* number;
    char** description;
    char* priority;
    Data* when;
} task_info;

typedef task_info* ptr_task;

int propose_action(FILE* stream_input); // нельзя протестировать, так как используется стандартный поток ввода
int make_choice(char *choice); // готово

char** create_string(); // протестировано
int delete_string(char** string); // протестировано
ptr_task create_task(); // протестировано
int delete_task(ptr_task task); // протестировано

int set_task(ptr_task task, FILE* stream_input); // нельзя протестировать, так как вызываются функции использующие стандартный поток ввода

int print_task(ptr_task task); // протестировано при вызове print list
int print_description(char** string); // протестировано при вызове print list

char get_symbol(FILE* stream_input); // нельзя протестировать, так как используется стандартный поток ввода
char* get_string(FILE* stream_input); // нельзя протестировать, так как используется стандартный поток ввода

int get_number(FILE *stream_input, char* string); // нельзя протестировать, так как используется стандартный поток ввода
int get_description(FILE *stream_input, char** string); // нельзя протестировать, так как используется стандартный поток ввода
int get_priority(FILE *stream_input, char* string); // нельзя протестировать, так как используется стандартный поток ввода
int get_data(FILE *stream_input, Data* cur_data); // нельзя протестировать, так как используется стандартный поток ввода

#endif //  PROJECT_INCLUDE_TASK_INFO_H_
