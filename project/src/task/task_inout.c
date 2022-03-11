#include "../../include/task_info.h"
//#include "task_parser.h" по сути модуль parser.h понадобится только тут

// сделать проверку на размер вводимых данных
int set_task(ptr_task task) {
    if (task == NULL) {
        return -1;
    }

    printf("%s", "Enter task number: ");
    if (!(scanf("%1024s", task->number))) {
        scanf( "%*[^\n]" ); // buffer was cleared
        delete_task(task);
        perror("Input Error");
        return -1;
    }
    scanf( "%*[^\n]" ); // buffer was cleared
//    printf("%zu\n", *task->number); // отладка

// Переписать как в ВК себе скинул
    printf("%s", "Enter task description: ");
    if (!(scanf("%1024s", task->description))) {
        scanf( "%*[^\n]" ); // buffer was cleared
        delete_task(task);
        perror("Input Error");
        return -1;
    }
    scanf( "%*[^\n]" ); // buffer was cleared
//    printf("%s\n", task->description); // отладка

    printf("%s", "Enter task priority: ");
    if (!(scanf("%1024s", task->priority))) {
        scanf( "%*[^\n]" ); // buffer was cleared
        delete_task(task);
        perror("Input Error");
        return -1;
    }
    scanf( "%*[^\n]" ); // buffer was cleared
//    printf("%zu\n", *task->priority); // отладка

    printf("%s", "Enter task data: ");
    if (!(scanf("%1024s", task->when))) {
        scanf( "%*[^\n]" ); // buffer was cleared
        delete_task(task);
        perror("Input Error");
        return -1;
    }
//    printf("%lf\n", *task->when); // отладка
    scanf( "%*[^\n]" ); // buffer was cleared
    return 0;
}

int print_task(const ptr_task task) {
    if (task == NULL) {
        perror("Print_task() error");
        return ERROR;
    }
    // puts("Task exist"); // отладка
    if (task->number != NULL) {
//        puts("task field exist"); // отладка
        printf("%s\n", task->number);
    }
    if (task->description != NULL) {
//        puts("task field exist"); // отладка
        printf("%s\n", task->description);
    }
    if (task->priority != NULL) {
//        puts("task field exist"); // отладка
        printf("%s\n", task->priority);
    }
    if (task->when != NULL) {
//        puts("task field exist"); // отладка
        printf("%s\n", task->when);
    }
    return SUCCESS;
}
