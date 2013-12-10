#ifndef __RUE_DATASET_H
#define __RUE_DATASET_H

#include <stdio.h>
#include "khash.h"
#include "feature.h"
#include "sample.h"

KHASH_MAP_INIT_STR(StringBool, char);

#define StringBoolMap khash_t(stringBool)
#define make_StringBoolMap() kh_init(StringBool)

typedef char *CombinedFeature[];
typedef double FeatureSplit[];

typedef struct{
    RawSample **Samples;
    StringBoolMap FeatureKeys;
}RawDataSet;

#endif /* __RUE_DATASET_H */
