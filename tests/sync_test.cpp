#include <gtest/gtest.h>

extern "C" {
    #include "../sync_lib/matrix/matrix.h"
}

#define BIG_FILE "test_files/big.txt"
#define MEDIUM_FILE "test_files/medium.txt"
#define NORMAL_FILE "test_files/normal.txt"
#define SMALL_FILE "test_files/small.txt"

TEST(BUSINESS_LOGIC, business_logic) {
//    EXPECT_EQ(business_logic(), SUCCESS);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
