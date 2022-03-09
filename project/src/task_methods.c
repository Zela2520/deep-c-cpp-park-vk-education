#include "../include/task_info.h"

ptr_task create_task_list(ptr_task task_list) {
    task_list = NULL;
    ptr_task temp_task_list;
    while (1) {
        if (!(add_task(task_list, create_task(), sizeof(*task_list) / sizeof(task_info)))) {
            perror("task hasn't been created");
            return NULL;
        }
        temp_task_list = (ptr_task)realloc(task_list, sizeof(task_info));
        if (!(temp_task_list)) {
            perror("Memory allocation error");
            return NULL;
        }
        task_list = temp_task_list;
    }
    return task_list;
}

void delete_task_list(ptr_task task_list) {
    free(task_list);
}

int propose_action() {
    printf("%s\n,%s\n,%s\n,%s\n",
           "Enter task number: ", "Enter a description of the task: ",
           "Enter task priority: ", "Enter task date: ");
}

// сделать проверку на размер вводимых данных
int set_task(ptr_task cur_task) {
    if (cur_task == NULL) {
        return -1;
    }
    if (!(scanf("%zu", &task->number))) {
        perror("Input Error");
        return -1
    }
    if (!(scanf("%MAX_STR_SIZE", task->description))) {
        perror("Input Error")
        return -1;
    }
    if (!(scanf("%zu", &task->priority))) {
        perror("Input Error");
        return -1;
    }
    if (!(scanf("%lf", &task->when))) {
        perror("Input Error");
        return -1;
    }
    return 0;
}

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

void print_task(const ptr_task cur_task) {
    if (cur_task != NULL) {
        printf("%" PR_SIZET "u", &task->number);
        printf("%s", task->description);
        printf("%" PR_SIZET "u", &task->priority);
        printf("%lf", &task->when);
    }
    perror("No such task or task hasn't been created");
}

void print_task_list(const ptr_task task_list) {
    if (task_list != NULL) {
        for (size_t i = 0; i < sizeof(*task_list) / sizeof(task_info); ++i) {
            print_task(&task_list[i]);
        }
    }
    perror("No such tasklist or tasklist hasn't been created");
}

int add_task(ptr_task task_list, const ptr_task cur_task, size_t size) {
    if (task_list == NULL || cur_task == NULL) {
        perror("Tasks don't exist");
        return -1;
    }
    task_list[size] = cur_task;
    return 0;
}