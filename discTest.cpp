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
    return;
}

int main() {
    
    testMul(10,3,0);

    return 0;
}