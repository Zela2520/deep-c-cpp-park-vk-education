#include "../include/task_info.h"

#define SUCCESS 0
#define ERROR -1
#define INCORRECT 1

ptr_task create_task() {
    ptr_task task = (task_info*)calloc(1, sizeof(task_info));
    if (task == NULL) {
        perror("Memory allocation error");
        return NULL;
    }

    if (!(task->number = (size_t*)calloc(1, sizeof(size_t)))) {
        perror("Memory allocation error");
        free(task);
        memset(task, 0, sizeof(*task));
        return NULL;
    }
    if (!(task->description = (char*)calloc(MAX_STR_SIZE + 1, sizeof(char)))) {
        perror("Memory allocation error");
        free(task->number);
        free(task);
        memset(task, 0, sizeof(*task));
        return NULL;
    }
    if (!(task->priority = (size_t*)calloc(1, sizeof(size_t)))) {
        perror("Memory allocation error");
        free(task->number);
        free(task->description);
        free(task);
        memset(task, 0, sizeof(*task));
        return NULL;
    }
    if (!(task->when = (double *)calloc(1, sizeof(double)))) {
        perror("Memory allocation error");
        free(task->number);
        free(task->description);
        free(task->priority);
        free(task);
        memset(task, 0, sizeof(*task));
        return NULL;
    }

    if (set_task(task)) {
        perror("Task hasn't been set");
        free(task->number);
        free(task->description);
        free(task->priority);
        free(task->when);
        free(task);
        memset(task, 0, sizeof(*task));
        return NULL;
    }

    return task;
}

// сделать проверку на размер вводимых данных
int set_task(ptr_task cur_task) {
    if (cur_task == NULL) {
        return -1;
    }
    if (!(scanf("%zu", &task->number))) {
        scanf( "%*[^\n]" ); // buffer was cleared
        perror("Input Error");
        return -1
    }
    scanf( "%*[^\n]" ); // buffer was cleared
    if (!(scanf("%1024s", task->description))) {
        scanf( "%*[^\n]" ); // buffer was cleared
        perror("Input Error")
        return -1;
    }
    scanf( "%*[^\n]" ); // buffer was cleared
    if (!(scanf("%zu", &task->priority))) {
        scanf( "%*[^\n]" ); // buffer was cleared
        perror("Input Error");
        return -1;
    }
    scanf( "%*[^\n]" ); // buffer was cleared
    if (!(scanf("%lf", &task->when))) {
        scanf( "%*[^\n]" ); // buffer was cleared
        perror("Input Error");
        return -1;
    }
    scanf( "%*[^\n]" ); // buffer was cleared
    return 0;
}

int add_task(ptr_task task_list, const ptr_task cur_task, size_t size) {
    if (task_list == NULL || cur_task == NULL) {
        perror("Tasks don't exist");
        return -1;
    }
    task_list[size] = cur_task;
    return 0;
}

void print_task(const ptr_task cur_task) {
    if (cur_task != NULL) {
        printf("%zu\n", &task->number);
        printf("%-1024s\n", task->description);
        printf("%zu\n", &task->priority);
        printf("%lf\n", &task->when);
    }
    perror("No such task or task hasn't been created");
}

void delete_task(ptr_task task) {
    if (task != NULL && task->number != NULL) {
        free(task->number);
        task->number = NULL;
    }
    if (task != NULL && task->description != NULL) {
        free(task->description);
        task->description = NULL;
    }
    if (task != NULL && task->priority != NULL) {
        free(task->priority);
        task->priority = NULL;
    }
    if (task != NULL && task->when != NULL) {
        free(task->when);
        task->when = NULL;
    }
    if (task != NULL) {
        free(task);
        task = NULL;
    }
}