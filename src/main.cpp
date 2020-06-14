/*
 * main.cpp
 *   created on: March 6, 2020
 *       author: shengcailiu
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
TIndi gBest;	// global best solution
int optimum;	// optimum cost

void signalHandler(int signum)
{
	cout << endl
		 << "Signal (" << signum << ") received.\n";
	cout << endl;
	printf("bestval = %d, optimum = %d \n", gBestValue, optimum);
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
	signal(SIGKILL, signalHandler);

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

	cout<<"Initialization ..."<<endl;
	gEnv->define();
	for (int n = 0; n < 1000000; ++n)
	{
		printf("Run %d\n", n);
		gEnv->doIt();
		if (gBestValue != -1 && gBestValue <= optimum) break;
	}
	gEnv->printOn();

	return 0;
}
