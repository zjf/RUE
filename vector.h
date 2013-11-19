#include <stdio.h>
#include <math.h>
#include <inttypes.h>
#include "khash.h"

KHASH_MAP_INIT_INT64(SparseVector, double);

#define SparseVectorMap khash_t(SparseVector)
#define make_SparseVectorMap() kh_init(SparseVector)


typedef struct Vector{
    SparseVectorMap *data;
}Vector;

inline Vector *NewVector();
inline void DestroyVector(Vector *v);
inline uint32_t GetSize(Vector *v);
inline void AddValue(Vector *v, int64_t key, double value);
inline double GetValue(Vector *v, int64_t key, int *ret);
inline void SetValue(Vector *v, int64_t key, double value);
inline void RandomInit(Vector *v, int64_t key, double c);
inline void AddVector(Vector *v, Vector *v2, double alpha);
inline double NormL2(Vector *v);
inline Vector *Copy(Vector *v);
inline double Dot(Vector *v, Vector *v2);

typedef double (*ElemOperation)(double val);
inline Vector *ApplyOnElem(Vector *v, ElemOperation f);
inline Vector *Scale(Vector *v, double scale);
inline Vector *ElemWiseAddVector(Vector *v, Vector *u);
inline Vector *ElemWiseMultiply(Vector *v, Vector *u);
