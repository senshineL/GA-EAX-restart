/*
 * main.cpp
 *   created on: Oct 6, 2020
 *       author: shengcailiu (liusccc@gmail.com)
 */

#ifndef __ENVIRONMENT__
#include "environment.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <csignal>
#include <iostream>
using namespace std;

int gBestValue = -1; // global best value
TIndi gBest; // global best solution
int optimum; // optimum cost
int duration; // used time

void signalHandler(int signum)
{
    cout << endl
         << "Signal (" << signum << ") received.\n";
    cout << endl;

    printf("Total time: %d\n", duration);
    printf("bestval = %d, optimum = %d \n", gBestValue, optimum);

    int Ncity = gBest.fN;
    int *Array = new int[Ncity];
    int curr = 0, st = 0, count = 0, pre = -1, next;
    while (1)
    {
        Array[count++] = curr + 1;
        if (count > Ncity)
        {
            printf("Invalid\n");
            return;
        }
        if (gBest.fLink[curr][0] == pre)
            next = gBest.fLink[curr][1];
        else
            next = gBest.fLink[curr][0];

        pre = curr;
        curr = next;
        if (curr == st)
            break;
    }
    printf("%d %d\n", gBest.fN, gBest.fEvaluationValue);
    for (int i = 0; i < gBest.fN; ++i)
        printf("%d ", Array[i]);
    printf("\n");

    if (gBestValue != -1 && gBestValue <= optimum)
        printf("Successful\n");
    else
        printf("Unsuccessful\n");
    fflush(stdout);

    exit(signum);
}

int main( int argc, char* argv[] )
{
    signal(SIGTERM, signalHandler);
    signal(SIGINT, signalHandler);

    TEnvironment* gEnv = new TEnvironment();
    gEnv->fFileNameTSP=(char*)malloc(100);

    // ./GA-EAX-restart tsp_file NPOP NCH optimum tmax
    // default: 100, 30, -1(unknown optimum), 3600
    if(argc != 7)
    {
        cout << "./GA-EAX-restart tsp_file NPOP NCH optimum tmax seed";
        exit(-1);
    }
    gEnv->fFileNameTSP = argv[1];
    gEnv->Npop = atoi(argv[2]);
    gEnv->Nch = atoi(argv[3]);
    optimum = gEnv->optimum = atoi(argv[4]);
    gEnv->tmax = atoi(argv[5]);
    InitURandom(atoi(argv[6]));
    gEnv->terminate = false;

    cout<<"Initialization ..."<<endl;
    gEnv->define();
    for (int n = 0; n < 1000000; ++n)
    {
        printf("Run %d\n", n);
        gEnv->doIt();
        if (gEnv->terminate) break;
    }
    gEnv->printOn();

    return 0;
}
