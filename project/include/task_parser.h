#ifndef PROJECT_INCLUDE_TASK_PARSER_H_
#define PROJECT_INCLUDE_TASK_PARSER_H_

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR_SIZE 1024

#define ERROR -1
#define SUCCESS 0
#define INCORRECT 1

int parser_number(const char* number);
int parser_description(const char** description);
int parser_priority(const char* priority);
int parser_data(const char* data);


//// сделать проверку на размер вводимых данных
//int set_task(ptr_task task, FILE* input_stream) {
//    if (task == NULL) {
//        return ERROR;
//    }
//
//    printf("%s", "Enter task number: ");
//    if (!(scanf("%1024s", task->number))) {
//        scanf("%*[^\n]"); // buffer was cleared
//        delete_task(task);
//        perror("Input Error");
//        return ERROR;
//    }
//
//    scanf("%*[^\n]"); // buffer was cleared
////    printf("%zu\n", *task->number); // отладка
//
//// Переписать как в ВК себе скинул
//    printf("%s", "Enter task description: ");
//    if (!(scanf("%1024s", task->description))) {
//        scanf("%*[^\n]"); // buffer was cleared
//        delete_task(task);
//        perror("Input Error");
//        return ERROR;
//    }
//
//    scanf("%*[^\n]"); // buffer was cleared
////    printf("%s\n", task->description); // отладка
//
//    printf("%s", "Enter task priority: ");
//    if (!(scanf("%1024s", task->priority))) {
//        scanf("%*[^\n]"); // buffer was cleared
//        delete_task(task);
//        perror("Input Error");
//        return ERROR;
//    }
//
//    scanf("%*[^\n]"); // buffer was cleared
////    printf("%zu\n", *task->priority); // отладка
//
//    printf("%s", "Enter task data: ");
//    if (!(scanf("%1024s", task->when))) {
//        scanf("%*[^\n]"); // buffer was cleared
//        delete_task(task);
//        perror("Input Error");
//        return ERROR;
//    }
//
//    scanf("%*[^\n]"); // buffer was cleared
////    printf("%lf\n", *task->when); // отладка
//
//    return 0;
//}

#endif //  PROJECT_INCLUDE_TASK_PARSER_H_