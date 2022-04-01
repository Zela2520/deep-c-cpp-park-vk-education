#include <gtest/gtest.h>

extern "C" {
    #include "../sync_lib/matrix/matrix.h"
}

#define BIG_FILE "test_files/big.txt"
#define MEDIUM_FILE "test_files/medium.txt"
#define NORMAL_FILE "test_files/normal.txt"
#define SMALL_FILE "test_files/small.txt"

TEST(MATRIX, create_matrix_from_file) {
//    EXPECT_EQ(async_business_logic(), SUCCESS);
}

TEST(MATRIX, create_matrix) {
//    EXPECT_EQ(async_business_logic(), SUCCESS);
}

TEST(MATRIX, free_matrix) {
//    EXPECT_EQ(async_business_logic(), SUCCESS);
}

TEST(MATRIX, print_result) {
//    EXPECT_EQ(async_business_logic(), SUCCESS);
}

TEST(LOGIC, calculate_sum_cols) {
//    EXPECT_EQ(async_business_logic(), SUCCESS);
}

TEST(LOGIC, business_logic) {
//    EXPECT_EQ(async_business_logic(), SUCCESS);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
