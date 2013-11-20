#ifndef __RUE_FEATURE_H
#define __RUE_FEATURE_H

#include <stdio.h>
#include <inttypes.h>

typedef FeatureType int;

enum FeatureTypeEnum{
    DISCRETE_FEATURE;
    CONTINUOUS_FEATURE;
}

FeatureType GetFeatureType(char *key);

typedef struct Feature{
    int64_t Id;
    double Value;
}Feature;

#endif /* __RUE_FEATURE_H */
