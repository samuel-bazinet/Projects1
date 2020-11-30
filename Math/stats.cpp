
#include"stats.h"

float variance(float, float, int);

double binomial(int n, int x, float Pi) {
    double ans;

    ans = combination(n,x)*pow(Pi,x)*pow(1-Pi,n-x);

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

unsigned int long long factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n*factorial(n-1);
}

unsigned int long long combination(int n, int r) {
    if ((n - r) > r) {
        return (optiFact(n, n-r) / factorial(r));
    } else {
        return (optiFact(n, r) / factorial(n-r));
    }
}

unsigned int long long optiFact(int n, int r) {
    if (n == r) {
        return 1;
    } else {
        return n*optiFact(n-1, r);
    }
}

void printUsefulBits() {

    std::string inString;
    float tot;
    float totSquare;
    int n = 0; 

    do {
        std::cout << "Input val, or 'n' if you want to end: ";
        std::cin >> inString;
        if (inString != "n") {
            n++;
            tot += std::stof(inString);
            totSquare += pow(std::stod(inString), 2);
        }

    } while (inString != "n");

    std::cout << "n: " << n << std::endl;
    std::cout << "Sum: " << tot << std::endl;
    std::cout << "Sum of Squares: " << totSquare << std::endl;
    std::cout << "mean: " << tot/n << std::endl;
    std::cout << "variance: " << variance(tot, totSquare, n) << std::endl;
    std::cout << "standard deviation: " << sqrt(variance(tot, totSquare, n)) << std::endl;


}   

float variance(float tot, float totSquare, int n) {
    if (n == 1) {
        return -1;
    }
    return ((totSquare - (pow((double)tot,2)/n))/(n-1));
}