#include "vector.h"

inline Vector *NewVector(){
    Vector *v;
    v = malloc(sizeof(Vector));
    v->data = make_SparseVectorMap();
    return v;
}

inline void DestroyVector(Vector *v){
    kh_destroy(SparseVector, v->data);
    free(v);
}

inline uint32_t GetSize(Vector *v){
    return v->data->size;
}

inline void AddValue(Vector *v, int64_t key, double value){
    khiter_t k;
    int ret;
    k = kh_get(SparseVector, v->data, key);
    if(k == kh_end(v->data)){
        k = kh_put(SparseVector, v->data, key, &ret);
        kh_value(v->data, k) = value;
    }else{
        kh_value(v->data, k) += value;
    }
}

inline double GetValue(Vector *v, int64_t key, int *ret){
    khiter_t k;
    k = kh_get(SparseVector, v->data, key);
    if(k == kh_end(v->data)){
        *ret = 0;
        return 0.0;
    }else{
        *ret = 1;
        return kh_value(v->data, k);
    }
}

inline void SetValue(Vector *v, int64_t key, double value){
    int ret;
    khiter_t k;
    k = kh_get(SparseVector, v->data, key);
    if(k == kh_end(v->data)){
        k = kh_put(SparseVector, v->data, key, &ret);
    }
    kh_value(v->data, k) = value;
}

inline void RandomInit(Vector *v, int64_t key, double c){
    khiter_t k;
    k = kh_get(SparseVector, v->data, key);
    if(k != kh_end(v->data)){
        kh_value(v->data, k) = (rand() + 0.0) / RAND_MAX * c;
    }
}

inline void AddVector(Vector *v, Vector *v2, double alpha){
    khiter_t k;
    for(k = kh_begin(v2->data); k != kh_end(v2->data); k++){
        if(kh_exist(v2->data, k)){
            AddValue(v, kh_key(v2->data, k), kh_value(v2->data, k) * alpha);
        }
    }
}

inline double NormL2(Vector *v){
    khiter_t k;
    double ret = 0.0;
    for(k = kh_begin(v->data); k != kh_end(v->data); k++){
        if(kh_exist(v->data, k)){
            ret += kh_value(v->data, k) * kh_value(v->data, k);
        }
    }
    return ret;
}

inline Vector *Copy(Vector *v){
    Vector *v2 = NewVector();
    khiter_t k;
    for(k = kh_begin(v->data); k != kh_end(v->data); k++){
        if(kh_exist(v->data, k)){
            SetValue(v2, kh_key(v->data, k), kh_value(v->data, k));
        }
    }
    return v2;
}

inline double Dot(Vector *v, Vector *v2){
    Vector *va = v;
    Vector *vb = v2;
    if(GetSize(v2) < GetSize(v)){
        va = v2;
        vb = v;
    }
    double dot = 0.0;
    khiter_t k;
    int ret;
    for(k = kh_begin(va->data); k != kh_end(va->data); k++){
        if(kh_exist(va->data, k)){
            // if this key dose not exist in vb, GetValue will return 0.0 and the value checking of ret can be omitted.
            dot += kh_value(va->data, k) * GetValue(vb, kh_key(va->data, k), &ret);
        }
    }
    return dot;
}

// inline double DotFeatures(Vector *v, )

inline Vector *ApplyOnElem(Vector *v, ElemOperation f){
    Vector *v2 = NewVector();
    khiter_t k;
    for(k = kh_begin(v->data); k != kh_end(v->data); k++){
        if(kh_exist(v->data, k)){
            SetValue(v2, kh_key(v->data, k), f(kh_value(v->data, k)));
        }
    }
    return v2;
}

inline Vector *Scale(Vector *v, double scale){
    Vector *v2 = NewVector();
    khiter_t k;
    for(k = kh_begin(v->data); k != kh_end(v->data); k++){
        if(kh_exist(v->data, k)){
            SetValue(v2, kh_key(v->data, k), kh_value(v->data, k) * scale);
        }
    }
    return v2;
}

inline Vector *ElemWiseAddVector(Vector *v, Vector *u){
    Vector *v2 = Copy(v);
    khiter_t k;
    for(k = kh_begin(u->data); k != kh_end(u->data); k++){
        if(kh_exist(u->data, k)){
            AddValue(v2, kh_key(u->data, k), kh_value(u->data, k));
        }
    }
    return v2;
}

inline Vector *ElemWiseMultiply(Vector *v, Vector *u){
    Vector *v2 = NewVector();
    khiter_t k;
    int ret;
    double val, ual;
    for(k = kh_begin(v->data); k != kh_end(v->data); k++){
        if(kh_exist(v->data, k)){
            val = kh_value(v->data, k);
            ual = GetValue(u, kh_key(v->data, k), &ret);
            if(val != 0 && ual != 0){
                SetValue(v2, kh_key(v->data, k), val*ual);
            }
        }
    }
    return v2;
}
