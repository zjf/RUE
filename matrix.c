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

inline void MatrixAddValue(Matrix *m, int64_t k1, int64_t k2, double v){
    khiter_t k;
    int ret;
    k = kh_get(SparseMatrix, m->data, k1);
    if(k == kh_end(m->data)){
        k = kh_put(SparseMatrix, m->data, k1, &ret);
        kh_value(m->data, k) = NewVector();
    }
    AddValue(kh_value(m->data, k), k2, v);
}

inline void MatrixSetValue(Matrix *m, int64_t k1, int64_t k2, double v){
    khiter_t k;
    int ret;
    k = kh_get(SparseMatrix, m->data, k1);
    if(k == kh_end(m->data)){
        k = kh_put(SparseMatrix, m->data, k1, &ret);
        kh_value(m->data, k) = NewVector();
    }
    SetValue(kh_value(m->data, k), k2, v);
}

inline Vector* GetRow(Matrix *m, int64_t k1, int *ret){
    khiter_t k;
    k = kh_get(SparseMatrix, m->data, k1);
    if(k == kh_end(m->data)){
        *ret = 0;
        return NULL;
    }else{
        *ret = 1;
        return kh_value(m->data, k);
    }
}

inline void SetRow(Matrix *m, int64_t k1, Vector *v){
    int ret;
    khiter_t k;
    k = kh_get(SparseMatrix, m->data, k1);
    if(k == kh_end(m->data)){
        k = kh_put(SparseMatrix, m->data, k1, &ret);
    }
    kh_value(m->data, k) = Copy(v);
}

inline double MatrixGetValue(Matrix *m, int64_t k1, int64_t k2, int * ret){
    int row_exist;
    Vector *row = GetRow(m, k1, &row_exist);
    if(row_exist){
        return GetValue(row, k2, ret);
    }else{
        *ret = 0;
        return 0.0;
    }
}

inline Matrix *MatrixScale(Matrix *m, double scale){
    Matrix *ret = NewMatrix();
    khiter_t k, k1;
    int row_exist;
    for(k = kh_begin(m->data); k != kh_end(m->data); k++){
        if(kh_exist(m->data, k)){
            k1 = kh_put(SparseMatrix, ret->data, kh_key(m->data, k), &row_exist);
            kh_value(ret->data, k1) = Scale(kh_value(m->data, k), scale);
        }
    }
    return ret;
}

inline Vector *MultiplyVector(Matrix *m, Vector *v){
    // This is intended for l-by-m * m-by-1
	// For m-by-1 * 1-by-n, use OuterProduct in vector.go
	// Probably should just have a MatrixMultiply for everything
    Vector *ret = NewVector();
    khiter_t k;
    for(k = kh_begin(m->data); k != kh_end(m->data); k++){
        if(kh_exist(m->data, k)){
            SetValue(ret, kh_key(m->data, k), Dot(kh_value(m->data, k), v));
        }
    }
    return ret;
}

inline Matrix *Trans(Matrix *m){
    Matrix *ret = NewMatrix();
    khiter_t kr, kc;
    for(kr = kh_begin(m->data); kr != kh_end(m->data); kr++){
        if(kh_exist(m->data, kr)){
            Vector *row = kh_value(m->data, kr);
            for(kc = kh_begin(row->data); kc != kh_end(row->data); kc++){
                if(kh_exist(row->data, kc)){
                    MatrixSetValue(ret, kh_key(row->data, kc), kh_key(row->data, kr), kh_value(row->data, kc));
                }
            }
        }
    }
    return ret;
}

inline Matrix *ElemWiseAddMatrix(Matrix *m, Matrix *n){
    Matrix *ret = NewMatrix();
    khiter_t k, k1;
    for(k = kh_begin(m->data); k != kh_end(m->data); k++){
        if(kh_exist(m->data, k)){
            SetRow(ret, kh_key(m->data, k), kh_value(m->data, k));
        }
    }
    for(k = kh_begin(n->data); k != kh_end(n->data); k++){
        if(kh_exist(n->data, k)){
            k1 = kh_get(SparseMatrix, ret->data, kh_key(n->data, k));
            if(k1 == kh_end(ret->data)){
                SetRow(ret, kh_key(n->data, k), kh_value(n->data, k));
            }else{
                Vector *tmp = kh_value(ret->data, k1);
                kh_value(ret->data, k1) = ElemWiseAddVector(kh_value(n->data, k), tmp);
                DestroyVector(tmp);
            }
        }
    }
    return ret;
}
