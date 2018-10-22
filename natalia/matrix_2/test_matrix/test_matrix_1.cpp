# include "gtest/gtest.h"
# include "../src/matrix.h"



TEST(MatrixTrace, simple) {
EXPECT_EQ(0, matrix_trace({{0,0,0}{0,0,0},{0,0,0}}));
EXPECT_EQ(3, matrix_trace({{1,1,1}{1,1,1},{1,1,1}}));
EXPECT_EQ(3, matrix_trace({{1,0,0}{0,1,0},{0,0,1}}));
//EXPECT_GT(factorial(-10), 0);
}


