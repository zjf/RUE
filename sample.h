#ifndef __RUE_SAMPLE_H
#define __RUE_SAMPLE_H

#include <stdio.h>
#include <math.h>
#include <inttypes.h>
#include "khash.h"
#include "feature.h"

KHASH_MAP_INIT_STR(String, char *);

#define StringMap khash_t(String)
#define make_StringMap() kh_init(String)

typedef struct RawSample{
    StringMap *Features;
    int Label;
    double Prediction;
}RawSample;


#endif /* __RUE_SAMPLE_H */
