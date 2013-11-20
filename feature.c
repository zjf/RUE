#include "feature.h"

FeatureType GetFeatureType(char *key){
    if(key[0] == '#'){
        return DISCRETE_FEATURE;
    }else{
        return CONTINUOUS_FEATURE;
    }
}
