#include "../../include/task_info.h"


char get_symbol(FILE *input_stream) {

    return symbol;
}

int get_number(FILE *stream_input, char* string) {
    return SUCCESS;
}

int get_description(FILE* stream_input, char** string) {
    if (string == NULL) {
        perror("set string error");
        return ERROR;
    }

    for (size_t i = 0; i < MAX_STR_SIZE && string[i] != NULL; ++i) {
        if (fscanf(input_stream, "%1024s", s[i])) {
            perror("Memory input error");
            scanf("%*[^\n]");
            return ERROR;
        }
        scanf("%*[^\n]");
    }
}

int get_priority(FILE *stream_input, char* string) {
    return SUCCESS;
}

int get_data(FILE *stream_input, char* string) {
    return SUCCESS;
}