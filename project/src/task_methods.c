#include "../include/task_info.h"

#define SUCCESS 0
#define ERROR -1
#define INCORRECT 1

ptr_task create_task_list(ptr_task task_list) {
    if (task_list != NULL) {
        free(task_list);
        task_list = NULL;
    }
    ptr_task temp_task_list;
    while (propose_action() == SUCCESS) {
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

ptr_task sort_task_list() {
    return NULL;
}

void print_task_list(const ptr_task task_list) {
    if (task_list != NULL) {
        for (size_t i = 0; i < sizeof(*task_list) / sizeof(task_info); ++i) {
            print_task(&task_list[i]);
        }
    }
    perror("No such tasklist or tasklist hasn't been created");
}

void delete_task_list(ptr_task task_list) {
    if (task_list == NULL) {
        perror("No such tasklist or tasklist hasn't been created");
        return;
    }
    for (size_t i = 0; i < sizeof(*task_list) / sizeof(task_info); ++i) {
        delete_task(&task_list[i]);
    }
    task_list = NULL;
}

int propose_action() {
    char *choice = (char *) calloc(10, sizeof(char));

    do {
            if (printf("%-42s", "Would you like to add a new task? Yes/No:") < 0) {
                perror("Data entry error");
                return ERROR;
            }

            if (!(scanf("%5s", choice))) {
                perror("Data entry error");
                scanf( "%*[^\n]" ); // buffer was cleared
                free(choice);
                return ERROR;
            }
            scanf( "%*[^\n]" ); // buffer was cleared
    } while (make_choice(choice) == ERROR);

    if (make_choice(choice) == INCORRECT) {
        puts("Task entry has been stopped");
        free(choice);
        return INCORRECT;
    }

    if (!(make_choice(choice))) {
        printf("%s\n%s\n%s\n%s\n",
               "Enter task number: ", "Enter a description of the task: ",
               "Enter task priority: ", "Enter task date: ");
        free(choice);
    }
    return SUCCESS;
}

int make_choice(char *choice) {
    if ((strlen(choice) == (strlen("No")) && strncmp(choice, "No", 2) == 0)) {
        return INCORRECT;
    }
    if ((strlen(choice) == (strlen("Yes")) && strncmp(choice, "Yes", 3) == 0)) {
        return SUCCESS;
    }
    puts("Invalid data entered, please check again!");
    return ERROR;
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

// сделать проверку на размер вводимых данных
int set_task(ptr_task task) {
    if (task == NULL) {
        return -1;
    }
    if (!(scanf("%zu", task->number))) {
        scanf( "%*[^\n]" ); // buffer was cleared
        perror("Input Error");
        return -1;
    }
    scanf( "%*[^\n]" ); // buffer was cleared
    if (!(scanf("%1024s", task->description))) {
        scanf( "%*[^\n]" ); // buffer was cleared
        perror("Input Error");
        return -1;
    }
    scanf( "%*[^\n]" ); // buffer was cleared
    if (!(scanf("%zu", task->priority))) {
        scanf( "%*[^\n]" ); // buffer was cleared
        perror("Input Error");
        return -1;
    }
    scanf( "%*[^\n]" ); // buffer was cleared
    if (!(scanf("%lf", task->when))) {
        scanf( "%*[^\n]" ); // buffer was cleared
        perror("Input Error");
        return -1;
    }
    scanf( "%*[^\n]" ); // buffer was cleared
    return 0;
}



int add_task(ptr_task task_list, const ptr_task task, size_t size) {
    if (task_list == NULL || task == NULL) {
        perror("Tasks don't exist");
        return -1;
    }
    task_list[size] = *task;
    return 0;
}

void print_task(const ptr_task task) {
    if (task != NULL) {
        printf("%zu\n", *task->number);
        printf("%-1024s\n", task->description);
        printf("%zu\n", *task->priority);
        printf("%lf\n", *task->when);
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
