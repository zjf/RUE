#include "sample.h"

inline RawSample *NewRawSample(){
    RawSample *ret = malloc(sizeof(RawSample));
    ret->Features = make_StringMap();
    ret->Label = 0;
    ret->Prediction = 0.0;
    return ret;
}

inline void DestroyRawSample(RawSample *s){
    kh_destroy(String, s->Features);
    free(s);
}

inline char *GetFeatureValue(RawSample *s, char *key){
    khiter_t k;
    k = kh_get(String, s->Features, key);
    if(k != kh_end(s->Features)){
        return kh_value(s->Features, key);
    }else{
        return NULL;
    }
}

typedef Sample strcut{
    Feature *Features;
    int Label;
    double Prediction;
    int FeatureNumber;
    int FeatureCapacity;
}Sample;

inline Sample *NewSample(){
    Sample *ret = malloc(sizeof(Sample));
    ret->Features = NULL;
    ret->Lable = 0;
    ret->Prediction = 0.0;
    ret->FeatureNumber = 0;
    ret->FeatureCapacity = 0;
    return ret;
}

inline void DestroySample(Sample *s){
    free(s->Features);
    free(s);
}

inline double LableDoubleValue(Sample *s){
    if(s->Label > 0){
        return 1.0;
    }else{
        return 0.0;
    }
}

inline void AddFeature(Sample *s, Feature f){
    if(s->FeatureNumber == 0){
        s->FeatureCapacity = 1;
        s->Features = malloc(sizeof(Feature));
    }else if(s->FeatureNumber == s->FeatureCapacity){
        s->FeatureCapacity = s->FeatureCapacity * 2;
        s->Features = realloc(s->FeatureCapacity * sizeof(Feature));
    }
    s->Features[FeatureNumber].Id = f.Id;
    s->Features[FeatureNumber].Value = f.Value;
    s->FeatureNumber++;
}
