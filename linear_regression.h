#ifndef __RUE_LINEAR_REGRESSION_H
#define __RUE_LINEAR_REGRESSION_H

#include <stdio.h>
#include <math.h>
#include <inttypes.h>
#include "khash.h"
#include "vector.h"
#include "matrix.h"

typedef struct LinearRegressionParams{
}LinearRegressionParams;

typedef struct LinearRegression{
    Vector* Model;
}LinearRegression;

#endif /* __RUE_LINEAR_REGRESSION_H */
