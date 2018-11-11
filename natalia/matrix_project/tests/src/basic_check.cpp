#include "../../../../../googletest-master/googletest/include/gtest/gtest.h"
#include "../../libraries/ClassMatrix.h"

GTEST_API_ int main(int argc, char **argv) {
    printf("Running main() from gtest_main.cc\n");
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test_trace, Simple) {
    EXPECT_EQ(0, 0);

    double B0[1][1] ={-10.0};
    ClassMatrix C0 = {1, 1, *B0};
    EXPECT_EQ( C0.matrix_trace(C0),  -10.0  );

    double B1[1][1] ={1.0};
    ClassMatrix C1 = {1, 1, *B1};
    EXPECT_EQ( C1.matrix_trace(C1),  1.0  );

    double B2[2][2] ={{1.0, 0},
                      {0, 1.0}};
    ClassMatrix C2 = {2, 2, *B2};
    EXPECT_EQ( C2.matrix_trace(C2),  2.0  );

    double B3[3][3] ={{1.0, 1.0, 1.0},
                      {1.0, 1.0, 1.0},
                      {1.0, 1.0, 1.0}};
    ClassMatrix C3 = {3, 3, *B3};
    EXPECT_EQ( C3.matrix_trace(C3),  3.0  );


    double B4[4][4] = {{20.0, 13.1, 14.0, -6.38},
                       {15.2, 16.0, 17.4, 5.25},
                       {18.0, 19.3, 20.0, -9.99},
                       {25.45, 15.0, 57.1, 5.65}};
    ClassMatrix C4 = {4, 4, *B4};
    EXPECT_EQ( C4.matrix_trace(C4),  61.65  );
}

TEST(test_det, Simple) {
    double B2[2][2] ={{1.0, 0},
                      {0, 1.0}};
    ClassMatrix C2 = {2, 2, *B2};
    EXPECT_EQ(C2.matrix_determinant(C2), 1.0);

    double M2[2][2] = {{3.0, 3.0},
                    {3.0, 3.0}};
    ClassMatrix D2 = {2, 2, *M2};
    EXPECT_EQ(D2.matrix_determinant(D2), 0.0);

    double B3[3][3] ={{1.0, 1.0, 1.0},
                      {1.0, 1.0, 1.0},
                      {1.0, 1.0, 1.0}};
    ClassMatrix C3 = {3, 3, *B3};
    EXPECT_EQ( C3.matrix_determinant(C3),  0.0  );

    double M3[3][3] ={{2.0, 1.0, 1.0},
                      {1.0, 2.0, 1.0},
                      {1.0, 1.0, 2.0}};
    ClassMatrix D3 = {3, 3, *M3};
    EXPECT_EQ( D3.matrix_determinant(D3),  4.0  );
    /*double B4[4][4] = {{20.0, 13.1, 14.0, -6.38},
                       {15.2, 16.0, 17.4, 5.25},
                       {18.0, 19.3, 20.0, -9.99},
                       {25.45, 15.0, 57.1, 5.65}};
    ClassMatrix C4 = {4, 4, *B4};
    EXPECT_EQ( C4.matrix_determinant(C4),  81552.67  );*/
}