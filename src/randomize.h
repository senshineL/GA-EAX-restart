#ifndef __RAND__
#define __RAND__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

extern void InitURandom( int );
extern void InitURandom( void );

class TRandom {
public:
    TRandom();
    ~TRandom();
    int Integer( int minNumber, int maxNumber );
    double Double( double minNumber, double maxNumber );
    double normalDistribution( double mu, double sigma );
    void permutation( int *array, int numOfelement, int numOfSample );
    void shuffle( int *array, int numOfElement );
};

extern TRandom* tRand;

#endif


