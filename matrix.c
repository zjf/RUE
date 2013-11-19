#include "matrix.h"

inline Matrix *NewMatrix(){
    Matrix *m;
    m = malloc(sizeof(Matrix));
    m->data = make_SparseMatrixMap();
    return m;
}

inline void DestroyMatrix(Matrix *m){
    khiter_t k;
    for(k = kh_begin(m->data); k != kh_end(m->data); k++){
        if(kh_exist(m->data, k)){
            DestroyVector(kh_value(m->data, k));
        }
    }
    kh_destroy(SparseMatrix, m->data);
    free(m);
}
