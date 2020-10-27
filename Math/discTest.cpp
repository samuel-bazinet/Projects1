#include<iostream>
#include<math.h>
#include"stats.h"

void testCeiling() {
    for (float i = 0; i <= 100; i+= 0.1) {
        
        if (ceil(ceil(i/2)/2) == ceil(i/4)) {
            std::cout << "True" << std::endl;
        } else {
            std::cout << "False" << std::endl;
        }
    }
}

void testFactExp() {
    for (int i = 1; i < 11; i++) {
        std::cout << "factorial(" << i << ") - pow(2," << i << ") = " << factorial(i) - pow(2,i) << std::endl;
    }
}

void testMul(int max, int n, int counter) {

    std::cout << n << std::endl;

    if (counter == max) {
        return;
    }


    testMul(max, 2*n, counter + 1);
    
}

void testRecur(int n, int max, int counter) {

    std::cout << 3*n << std::endl; 

    if (max == counter) {    
        return;
    }

    testRecur(3*n,max, counter + 1);

}

void testRecur(int a1, int a2, int max, int counter) {

    std::cout << counter*a1 + pow(counter,2)*a2 << std::endl;

    if (max == counter) {
        return;
    }

    testRecur( counter*a1 + pow(counter,2)*a2, a1, max, counter+1);

}

void testRecur(int a1, int a2, int a3, int max, int counter) {

    std::cout << a1 + a3 << std::endl;

    if (max == counter) {
        return;
    }

    testRecur(a1 + a3, a1, a2, max, counter + 1);

}

int gcd(int a, int b) {
    int x = a;
    int y = b;
    while (y != 0) {
        int r = x%y;
        x = y;
        y = r;
    }
    return x;
}

int main() {

    //testRecur(100,10,1);  
    std::cout << gcd(12036, 1020) << std::endl;  

    return 0;
}