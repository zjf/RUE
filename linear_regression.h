#ifndef __RUE_LINEAR_REGRESSION_H
#define __RUE_LINEAR_REGRESSION_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <inttypes.h>
#include "khash.h"
#include "vector.h"
#include "matrix.h"

typedef struct LinearRegressionParams{
    double LearningRate;
    double Regularization;
    int Steps;
}LinearRegressionParams;

typedef struct LinearRegression{
    Vector* Model;
    LinearRegressionParams Params;
}LinearRegression;

#endif /* __RUE_LINEAR_REGRESSION_H */
