#include "linear_regression.h"

inline void LinearRegressionInit(LinearRegression *algo, int argc, char *argv[]){
    int i;
    for(i = 0; i < argc; i++){
        if(argv[i][1] == '-'){
            switch(argv[i][1]){
            case 'l':
                algo->Params.LearningRate = atof(argv[++i]);
                break;
            case 'r':
                algo->Params.Regularization = atof(argv[++i]);
                break;
            default:
                printf("Unrecognized option: %c\n", argv[i][1]);
                break;
            }
        }
    }
}

