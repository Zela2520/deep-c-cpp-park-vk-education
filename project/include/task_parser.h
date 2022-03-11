#ifndef PROJECT_INCLUDE_TASK_PARSER_H_
#define PROJECT_INCLUDE_TASK_PARSER_H_

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR_SIZE 1024

#define SUCCESS 0
#define ERROR -1
#define INCORRECT 1

int parser_number(char* number);
int parser_description(char* description);
int parser_priority(char* priority);
int parser_data(char* data);

#endif //  PROJECT_INCLUDE_TASK_PARSER_H_