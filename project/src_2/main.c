#include "../include/task_list.h"

int main(void) {
    list* user_list = create_list(DEFAULT_SIZE);

    if (user_list == NULL) {
        perror("creat list error");
    }

    if (business_logic(user_list)) {
        perror("business logic error");
    }

    if (print_list(user_list)) {
        perror("print list error");
    }

    if (free_list(user_list)) {
        perror("memory free error");
    }

    return 0;
}