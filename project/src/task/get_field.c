#include "../../include/task_info.h"

char get_symbol(FILE *stream_input) {
    char symbol = '\0';

    if (stream_input == NULL) {
        perror("get symbol error");
        return symbol;
    }

    while (fscanf(stream_input, "%c", &symbol) != 1);
    return symbol;
}

char* get_string(FILE *stream_input) {
    if (stream_input == NULL) {
        perror("get string error");
        return NULL;
    }

    struct buffer {
        char* string;
        size_t size;
        size_t capacity;
    } buf = {0};

    char c;
    while (c = get_symbol(stream_input), c != EOF && c != '\n') {
        if (buf.size + 1 >= buf.capacity) {
            size_t new_capacity = !buf.capacity ? 1 : buf.capacity * 2;
            char *tmp = (char*)malloc((new_capacity + 1) * sizeof(char));

            if (!tmp) {
                if (buf.string) {
                    free(buf.string);
                }
                return NULL;
            }

            if (buf.string) {
                tmp = strcpy(tmp, buf.string);
                free(buf.string);
            }

            buf.string = tmp;
            buf.capacity = new_capacity;
        }

        buf.string[buf.size] = c;
        buf.string[buf.size + 1] = '\0';
        ++buf.size;
    }
    return buf.string;
}

int get_number(FILE *stream_input, char* string) {

    char* temp = get_string(stream_input);
    if (temp == NULL) {
        perror("get number error");
        return ERROR;
    }

    if (strlen(temp) > MAX_NUMBER_SIZE || strlen(temp) == 0) {
        perror("get number error");
        return ERROR;
    }

    size_t i = strlen(temp);
    while (i) {
        if (!(s[i - 1] >= '0' && s[i - 1] <= '9')) {
            perror("get number error");
            return ERROR;
        }
        --i;
    }

    if (!(strcpy(string, temp))) {
        perror("string copy error");
        return ERROR;
    }

    free(temp);

    return SUCCESS;
}

int get_description(FILE* stream_input, char** string) {
    // должны читать строки до того момента пока очередная строка не начнется с '\0'
    if (string == NULL || stream_input == NULL) {
        perror("set string error");
        return ERROR;
    }
    // если хотим как то поиграться с границами описания, то можем считывать символ новой строки задавать определённые услови и потом отматывать назад через fseek()
    size_t i = 0;
    while(fgets(stream_input[i], 10000, ))

    return SUCCESS;
}

int get_priority(FILE *stream_input, char* string) {
    char* temp = get_string(stream_input);

    if (temp == NULL) {
        perror("get priority error");
        return ERROR;
    }

    if (strlen(temp) > MAX_PRIORITY_SIZE || strlen(temp) == 0) {
        perror("get priority error");
        return ERROR;
    }

    size_t i = strlen(temp);
    while (i) {
        if (!(s[i - 1] >= '0' && s[i - 1] <= '9')) {
            perror("get priority error");
            return ERROR;
        }
        --i;
    }

    if (!(strcpy(string, temp))) {
        perror("string copy error");
        return ERROR;
    }

    free(temp);

    return SUCCESS;
}

int get_data(FILE *stream_input, char* string) {
    return SUCCESS;
}