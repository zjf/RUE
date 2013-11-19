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


#endif /* __RUE_MATRIX_H */
