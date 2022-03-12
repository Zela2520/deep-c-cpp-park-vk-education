#ifndef PROJECT_INCLUDE_TASK_INFO_H_
#define PROJECT_INCLUDE_TASK_INFO_H_

#include "task_parser.h"

#define MAX_CHOICE_SIZE 10


#define FIELDS_NAMES 4
#define NUMBER 4
#define DESCRIPTION 3
#define PRIORITY 2
#define WHEN 1

typedef struct {
    char* number; // число в диапазоне [0, 100]
    char** description; // необходимо заменить на массив строк char* str[]
    char* priority; // число в диапазоне [0, 100]
    char* when; // формат даты 12.12.2022
} task_info;

typedef task_info* ptr_task;

int propose_action(FILE* stream_input); // не готово
int make_choice(char *choice); // готово

int create_string(char** string); // готово
int delete_string(char** string); // готово

ptr_task create_task(FILE* stream_input); // готово
int delete_task(ptr_task task); // готово
int set_task(ptr_task task, FILE* input_stream); // не готово

int print_task(ptr_task task); // готово
int print_description(char** string); // готово

char get_symbol(FILE* stream_input); // готово
char* get_string(FILE* stream_input); // готово

int get_number(FILE *stream_input, char* string); // не готово
int get_description(FILE *stream_input, char** string); // не готово
int get_priority(FILE *stream_input, char* string); // не готово
int get_data(FILE *stream_input, char* string); // не готово

#endif //  PROJECT_INCLUDE_TASK_INFO_H_
