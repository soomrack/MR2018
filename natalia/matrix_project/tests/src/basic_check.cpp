#include "../../../../../googletest-master/googletest/include/gtest/gtest.h"
#include "../../libraries/ClassMatrix.h"

GTEST_API_ int main(int argc, char **argv) {
    printf("Running main() from gtest_main.cc\n");
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test_trace, Simple) {
    EXPECT_EQ(0, 0);

    double B0[1];
    B0[0] = -10.0;
    ClassMatrix C0 = { 1, 1, B0};
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

TEST(test_det, Simple_2) {
    double B2[2][2] = {{1.0, 0},
                       {0,   1.0}};
    ClassMatrix C2 = {2, 2, *B2};
    EXPECT_EQ(C2.matrix_determinant(C2), 1.0);

    double M2[2][2] = {{3.0, 3.0},
                       {3.0, 3.0}};
    ClassMatrix D2 = {2, 2, *M2};
    EXPECT_EQ(D2.matrix_determinant(D2), 0.0);
}
    TEST(test_det, Simple_3) {

    double B3[3][3] = {{1.0, 1.0, 1.0},
                       {1.0, 1.0, 1.0},
                       {1.0, 1.0, 1.0}};
    ClassMatrix C3 = {3, 3, *B3};
    EXPECT_EQ(C3.matrix_determinant(C3), 0.0);

    double M3[3][3] = {{2.0, 1.0, 1.0},
                       {1.0, 2.0, 1.0},
                       {1.0, 1.0, 2.0}};
    ClassMatrix D3 = {3, 3, *M3};
    EXPECT_EQ(D3.matrix_determinant(D3), 4.0);
}
/*TEST(test_det, Simple_4) {
    double B4[4][4] = {{20.0, 13.1, 14.0, -6.38},
                       {15.2, 16.0, 17.4, 5.25},
                       {18.0, 19.3, 20.0, -9.99},
                       {25.45, 15.0, 57.1, 5.65}};
    ClassMatrix C4 = {4, 4, *B4};
    EXPECT_EQ( C4.matrix_determinant(C4),  81552.67  );
}*/

TEST(test_sum, Simple_2) {
    double B2[2][2] = {{1.0, 0},
                       {0,   1.0}};
    ClassMatrix C2 = {2, 2, *B2};

    double M2[2][2] = {{3.0, 3.0},
                       {3.0, 3.0}};
    ClassMatrix D2 = {2, 2, *M2};
    double* K2_data = new double [ 2 * 2 * sizeof(double)];
    ClassMatrix K2 = {2,2,K2_data};
    K2 = matrix_sum(C2, D2, K2);

    double N2[2][2] = {{4.0, 3.0},
                       {3.0, 4.0}};
    ClassMatrix S2 = {2,2,*N2};

    for (int i = 0; i<2; i++){
        for (int j=0; j<2; j++){
            double exp = S2.data[i*2+j];
            double eq = K2.data[i*2+j];
            EXPECT_EQ(eq,exp);
        }
    }
    delete(K2_data);

}

TEST(test_sum, Simple_3) {

    double B3[3][3] = {{1.0, 1.0, 1.0},
                       {1.0, 1.0, 1.0},
                       {1.0, 1.0, 1.0}};
    ClassMatrix C3 = {3, 3, *B3};

    double M3[3][3] = {{2.0, 1.0, 1.0},
                       {1.0, 2.0, 1.0},
                       {1.0, 1.0, 2.0}};
    ClassMatrix D3 = {3, 3, *M3};
    double* K3_data;
    ClassMatrix K3 = {3,3, K3_data};
    K3 = matrix_sum(C3,D3, K3);

    double N3[3][3] = {{3.0, 2.0, 2.0},
                       {2.0, 3.0, 2.0},
                       {2.0, 2.0, 3.0}};
    ClassMatrix S3 = {3, 3, *N3};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            double exp = S3.data[i * 3 + j];
            double eq = K3.data[i * 3 + j];
            EXPECT_EQ(eq, exp);
        }
    }
}

TEST(test_scalar, Simple_2) {
    double B2[2][2] = {{2.0, 5.0},
                       {10.0,   1.0}};
    ClassMatrix C2 = {2, 2, *B2};
    double K2[2][2] = {{4.0, 10.0},
                       {20.0,   2.0}};
    ClassMatrix S2 = {2, 2, *K2};
    const double scalar = 2.0;
    C2.matrix_mult__scalar(scalar,C2);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            double exp = S2.data[i * 2 + j];
            double eq = C2.data[i * 2 + j];
            EXPECT_EQ(eq, exp);
        }
    }
}