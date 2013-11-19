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

int main(int argc, char *argv[]){
    test_khash();
    return 0;
}
