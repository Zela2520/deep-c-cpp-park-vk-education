#include "matrix/matrix.h"

int main(void) {

    if (business_logic()) {
        perror("business logic error");
        return ERROR;
    }

    return 0;
}