### Introduction
GA-EAX-restart is a restart version of the powerful Genetic Algorithm with Edge Assembly Crossover (GA-EAX by [Nagata & Kobayashi, 2013]). In our massive experiments, GA-EAX-restart could consistantly outperform GA-EAX and LKH 2.0.9, the two state-of-the-art inexact solvers for TSP.

### Differences from GA-EAX
We have midified [GA-EAX](https://github.com/sugia/GA-for-TSP) to:

* perform restart whenever the original termination criterion is met
* terminate only when it finds a solution with given quality or a given time budget is exhausted
* accept command-line parameters

### Install
```
git clone git@github.com:senshineL/GA-EAX-restart.git
cd src
g++ -o ../bin/GA-EAX-restart -O3 main.cpp environment.cpp cross.cpp evaluator.cpp indi.cpp randomize.cpp kopt.cpp sort.cpp
```

### Usage
```
GA-EAX-restart path_to_tsp_file [pop_size] [offspring_size] [optimum] [cutoff_time] [random_seed]
```
Default values: pop_size 100, offspring_size 30

### LICENSE
This software is released under Apache License 2.0.