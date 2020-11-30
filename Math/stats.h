 // stats.h

 #ifndef STATS_H
 #define STATS_H

#include<iostream>
#include<cmath>
 
double binomial(int n, int x, float Pi);
double binoSeries(int n, float Pi, int s, int e);
double pow(double a, int x);

unsigned int long long factorial(int n);
unsigned int long long combination(int n, int r);
unsigned int long long optiFact(int n, int r);
void printUsefulBits();

#endif