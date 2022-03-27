#include "../include/task_list.h"

int main(void) {

    const char *input_stream_path = "tests/correct_data.txt";

    list* user_list = create_list(DEFAULT_SIZE);

    if (user_list == NULL) {
        perror("creat list error");
        return ERROR;
    }

    if (business_logic(user_list, input_stream_path)) {
        perror("business logic error");
        return ERROR;
    }

    if (!(sort_list(user_list))) {
        perror("sort_list error main error");
        return ERROR;
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
