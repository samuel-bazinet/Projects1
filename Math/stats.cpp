#include<iostream>
#include"stats.h"

double binomial(int n, int x, float Pi);
double binoSeries(int n, float Pi, int s, int e);
double pow(double a, int x);

long factorial(int n);

double binomial(int n, int x, float Pi) {
    double ans;

    ans = (factorial(n)/(factorial(x)*factorial(n-x)))*pow(Pi,x)*pow(1-Pi,n-x);

    return ans;
}

double binoSeries(int n, float Pi, int s, int e){
    double ans = 0;

    for (int i = s; i <= e; i++) {
        ans += binomial(n, i, Pi);
    }

    return ans;
}

double pow(double a, int x) {
    if (x == 1) {
        return a;
    } else if (x == 0) {
        return 1;
    }

    if (x % 2 == 0) {
        return pow(a*a, x/2);
    } else {
        return a * pow(a, x-1);
    }
}

long factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n*factorial(n-1);
}