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
    if (string == NULL || stream_input == NULL) {
        perror("get number error");
        return ERROR;
    }

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
    if (string == NULL || stream_input == NULL) {
        perror("set string error");
        return ERROR;
    }

    char new_line;

    while(new_line = get_symbol(stream_input), new_line != '\n' && new_line != EOF) {
        if (fseek(stream_input, -1, SEEK_CUR)) {
            perror("fseek error");
            return ERROR;
        }

        if (fgets(stream_input[i], MAX_STR_SIZE, stream_input) == NULL) {
            perror("fgets error");
            return ERROR;
        }
    }

    return SUCCESS;
}

int get_priority(FILE *stream_input, char* string) {
    if (string == NULL || stream_input == NULL) {
        perror("get priority error");
        return ERROR;
    }

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




static int check_data_num(int data_num) {
    if (data_num < 0 || data_num > 31) {
        perror("check data error");
        return ERROR;
    }
    return SUCCESS;
}

static int check_month(int month) {
    if (month < 0 || month > 12) {
        perror("check month error");
        return ERROR;
    }
    return SUCCESS;
}

static int check_year(int year) {
    if (year < 1930 || year > 2050) {
        perror("check month error");
        return ERROR;
    }
    return SUCCESS;
}

static char* strcut(char* begin, char end) {
    char* new_string = (char*)calloc(MAX_STR_SIZE, sizeof(char));

    for (size_t i = 0; begin[i] != end && begin[i] != '\0'; ++i) {
        new_string[i] += begin[i];
    }
    return new_string;
}




int get_data(FILE *stream_input, Data* cur_data) {
    if (string == NULL || stream_input == NULL) {
        perror("get data error");
        return ERROR;
    }

    char* temp_string = get_string(stream_input);

    if (strlen(temp_string) > MAX_DATA_SIZE || strlen(temp_string) == 0) {
        perror("get data error");
        return ERROR;
    }

    if (temp_string[FIRST_DIVIDER] != '.' && temp_string[FIRST_DIVIDER] != temp_string[SECOND_DIVIDER]) {
        perror("get data error");
        return ERROR;
    }

    char* cur_char = temp_string;

    for (size_t i = 0; i < PARTS_NUMBERS; ++i) {
        switch (i) {
            case FIRST_PART: {
                char* str_part_1 = strcut(cur_char, '.');
                if (check_data_num(atoi(str_part_1))) {
                    free(str_part_1);
                    str_part_1 = NULL;
                    free(temp_string);
                    temp_string = NULL;
                    return ERROR;
                }

                cur_data->number = atoi(str_part_1);
                free(str_part_1);
                str_part_1 = NULL;

                cur_char = strchr(cur_char, '.') + 1;
                break;
            }

            case SECOND_PART: {
                char* str_part_2 = strcut(cur_char, '.');
                if (check_month(atoi(str_part_2))) {
                    free(str_part_2);
                    str_part_2 = NULL;
                    free(temp_string);
                    temp_string = NULL;
                    return ERROR;
                }

                cur_data->month = atoi(str_part_2);
                free(str_part_2);
                str_part_2 = NULL;

                cur_char = strchr(cur_char, '.') + 1;
                break;
            }

            case THIRD_PART: {
                char* str_part_3 = strcut(cur_char, '.');
                if (check_year(atoi(str_part_3))) {
                    free(str_part_3);
                    str_part_3 = NULL;
                    free(temp_string);
                    temp_string = NULL;
                    return ERROR;
                }

                cur_data->year = atoi(str_part_3);
                free(str_part_3);
                str_part_3 = NULL;

                break;
            }
        }
    }

    free(temp_string);
    temp_string = NULL;
    return SUCCESS;
}