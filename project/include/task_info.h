#ifndef PROJECT_INCLUDE_TASK_INFO_H_
#define PROJECT_INCLUDE_TASK_INFO_H_

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR_SIZE 10000

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


typedef struct {
    char* number; // число в диапазоне [0, 100]
    char** description; // читаем строку, следующая строка должна начинаться с '\t' тогда считаем что описание продолжается, описание заканчивается когда следующая строка начинается не с '\t'
    char* priority; // число в диапазоне [0, 10]
    char* when; // формат даты 12.12.2022 (длина строки 10 символов, 2 и 5 символы точки)
} task_info;

typedef task_info* ptr_task;

int propose_action(FILE* stream_input); // не готово
int make_choice(char *choice); // готово

int create_string(char** string); // готово
int delete_string(char** string); // готово

ptr_task create_task(FILE* stream_input); // готово
int delete_task(ptr_task task); // готово
int set_task(ptr_task task, FILE* stream_input); // не готово

int print_task(ptr_task task); // готово
int print_description(char** string); // готово

char get_symbol(FILE* stream_input); // готово
char* get_string(FILE* stream_input); // готово

int get_number(FILE *stream_input, char* string); // готово
int get_description(FILE *stream_input, char** string); // не готово
int get_priority(FILE *stream_input, char* string); // готово
int get_data(FILE *stream_input, char* string); // не готово

#endif //  PROJECT_INCLUDE_TASK_INFO_H_
