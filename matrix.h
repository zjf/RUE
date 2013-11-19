#ifndef __RUE_MATRIX_H
#define __RUE_MATRIX_H

#include <stdio.h>
#include <math.h>
#include <inttypes.h>
#include "khash.h"
#include "vector.h"

KHASH_MAP_INIT_INT64(SparseMatrix, Vector*);

#define SparseMatrixMap khash_t(SparseMatrix)
#define make_SparseMatrixMap() kh_init(SparseMatrix)

typedef struct Matrix{
    SparseMatrixMap *data;
}Matrix;

inline Matrix *NewMatrix();
inline void DestroyMatrix(Matrix *m);
inline void MatrixAddValue(Matrix *m, int64_t k1, int64_t k2, double v);
inline void MatrixSetValue(Matrix *m, int64_t k1, int64_t k2, double v);
inline Vector* GetRow(Matrix *m, int64_t k1, int *ret);
inline void SetRow(Matrix *m, int64_t k1, Vector *v);
inline double MatrixGetValue(Matrix *m, int64_t k1, int64_t k2, int * ret);
inline Matrix *MatrixScale(Matrix *m, double scale);
inline Vector *MultiplyVector(Matrix *m, Vector *v);
inline Matrix *Trans(Matrix *m);
inline Matrix *ElemWiseAddMatrix(Matrix *m, Matrix *n);

#endif /* __RUE_MATRIX_H */
