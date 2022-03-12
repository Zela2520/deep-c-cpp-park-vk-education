#include "../include/task_list.h"

int main(int argc, const char **argv) {
    if (argc != 2) {
        perror("input path error");
        return ERROR;
    }

    const char *input_stream_path = argv[1];

    list* user_list = create_list(DEFAULT_SIZE);

    if (user_list == NULL) {
        perror("creat list error");
        return ERROR;
    }

    if (business_logic(user_list, input_stream_path)) {
        perror("business logic error");
        return ERROR,
    }

    if (print_list(user_list)) {
        perror("print list error");
        return ERROR;
    }

    if (free_list(user_list)) {
        perror("memory free error");
        return ERROR;
    }

    return 0;
}
