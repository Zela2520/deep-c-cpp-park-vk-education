#include "../../include/task_info.h"


int propose_action(FILE* stream_input) {
    if (stream_input == NULL) {
        return ERROR;
    }

    char *choice;

    do {
        if (printf("%-42s", "Would you like to add a new task? Yes/No:") < 0) {
            perror("Data entry error");
            return ERROR;
        }

        choice = get_string(stream_input);
        if (choice == NULL) {
            perror("Data entry error");
            return ERROR;
        }
    } while (make_choice(choice) == ERROR && !(feof(stream_input)));

    if (make_choice(choice) == INCORRECT) {
        puts("Task input stream has been stopped");
        free(choice);
        choice = NULL;
        return INCORRECT;
    }

    free(choice);
    choice = NULL;
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
