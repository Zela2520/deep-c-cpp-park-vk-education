#include "processes/processes.h"

int main(void) {

    if (async_business_logic()) {
        perror("business logic error");
        return ERROR;
    }

    return 0;
}