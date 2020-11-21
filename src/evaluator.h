#ifndef __EVALUATOR__
#define __EVALUATOR__

#ifndef __INDI__
#include "indi.h"
#endif

#include <string.h>
#include <assert.h>

class TEvaluator
{
public:
    TEvaluator();
    ~TEvaluator();
    void setInstance(char filename[]);/* Set the instance */
    void doIt(TIndi &indi);           /* Set the value of indi.fEvaluationValue */
    void writeTo(FILE *fp, TIndi &indi);     /* Write an tour to a file*/
    void writeToStdout( TIndi& indi ); /* Write a tour to stdout */
    bool checkValid(int *array, int value);  /* Check an tour */

    int fNearNumMax; /* Maximum number of k (see below) */
    int **fNearCity; /* NearCity[i][k]: k-th nearest city from */
    int **fEdgeDis;  /* EdgeDis[i][j]: distance between i and j */
    int Ncity;       /* Number of cities */
    double *x;       /* x[i]: x-coordinate of */
    double *y;       /* y[i]: x-coordinate of */
    int *Array;
};

#endif
