#include "../include/task_list.h"

int main() {

    const char *input_stream_path = "./start_server";

    list* user_list = create_list(DEFAULT_SIZE);

    if (user_list == NULL) {
        perror("creat list error");
        return ERROR;
    }

    if (business_logic(user_list, input_stream_path)) {
        if (free_list(user_list)) {
            perror("memory free error");
        }
        perror("business logic error");
        return ERROR;
    }

    if (!(sort_list(user_list))) {
        if (free_list(user_list)) {
            perror("memory free error");
        }
        perror("sort_list error main error");
        return ERROR;
    }

    if (print_list(user_list)) {
        if (free_list(user_list)) {
            perror("memory free error");
        }
        perror("print list error");
        return ERROR;
    }

    if (free_list(user_list)) {
        perror("memory free error");
        return ERROR;
    }

    return 0;
}
