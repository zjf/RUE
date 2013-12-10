#include "dataset.h"

int FindCategory(double split[], int len, double value){
    int i;
    for(i = 0; i < len; i++){
        if(split[i] >= value)
            return i;
    }
    return -1;
}


RawDataSet *NewRawDataSet(){
    RawDataSet *ret;
    ret = malloc(sizeof(RawDataSet));
    ret->Samples = malloc(sizeof(RawSample*));
    ret->FeatureKeys = make_StringBoolMap();
    ret->SampleNumber = 0;
    ret->SampleCapacity = 0;
    return ret;
}

void DestroyRawDataset(RawDataSet *d){
    int i;
    for(i = 0; i < d->SampleNumber; i++){
        DestroyRawSample(d->Samples[i]);
    }
    free(d->Samples);
    kh_destroy(StringBoolMap, d->FeatureKeys);
    free(d);
}

