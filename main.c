#include "main.h"

void test_khash(){
    Vector *v = NewVector();
    int ret;
    int i;
    int key[] = {1, 2, 1, 3, 4, 5, 6};
    double value[] = {23.1, 10.2, 4.2, 1, 2, 3, 4.0};
    for(i = 0; i < sizeof(key) / sizeof(int); i++){
        AddValue(v, key[i], value[i]);
        printf("After insert value %f at key %d:\n", value[i], key[i]);
        printf("  key : %d value: %f size: %u norm: %f\n", key[i], GetValue(v, key[i], &ret), GetSize(v), NormL2(v));
    }
    DestroyVector(v);
}

void test_matrix(){
    Matrix *a = NewMatrix();
    int rowkey[] = {3, 3};
    int colkey[] = {4, 4};
    double value[] = {1.78, -1.1};
    int i, j, ret;
    for(i = 0; i < sizeof(rowkey) / sizeof(int); i++){
        MatrixAddValue(a, rowkey[i], colkey[i], value[i]);
        printf("After insert value %f at key %d, %d:\n", value[i], rowkey[i], colkey[i]);
        printf("  key : %d, %d value: %f\n", rowkey[i], colkey[i], MatrixGetValue(a, rowkey[i], colkey[i], &ret));
    }
    DestroyMatrix(a);
    Matrix *b = NewMatrix();
    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            MatrixSetValue(b, i, j, 1.0);
        }
    }
    Matrix *c = MatrixScale(b, 2.0);
    printf("2.0 == %f ?\n", MatrixGetValue(c, 7, 8, &ret));
}

int main(int argc, char *argv[]){
    //test_khash();
    test_matrix();
    return 0;
}
