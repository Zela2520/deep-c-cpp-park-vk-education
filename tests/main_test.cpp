#include <gtest/gtest.h>

extern "C" {
    #include "../project/business_logic/business_logic.h"
}

#define BIG_FILE "test_files/big.txt"
#define MEDIUM_FILE "test_files/medium.txt"
#define NORMAL_FILE "test_files/normal.txt"
#define SMALL_FILE "test_files/small.txt"

TEST(MATRIX, create_matrix_from_file) {
    Matrix* user_matrix = NULL;
    EXPECT_TRUE(user_matrix == NULL);

    user_matrix = create_matrix_from_file("test_files/normal.txt");
    EXPECT_FALSE(user_matrix == NULL);

    EXPECT_FALSE(user_matrix->matrix == NULL);
    EXPECT_EQ(user_matrix->rows, 3);
    EXPECT_EQ(user_matrix->columns, 6);

    free_matrix(user_matrix);
}

TEST(BUSINESS_LOGIC, business_logic) {
    EXPECT_EQ(business_logic(), SUCCESS);
}

TEST(MATRIX, create_matrix) {

}

TEST(MATRIX, free_matrix) {

}

TEST(MATRIX, calculate_sum_cols) {

}

TEST(MATRIX, print_result) {

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}