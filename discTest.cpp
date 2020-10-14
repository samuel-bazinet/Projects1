#include<iostream>
#include<math.h>

int main() {
    for (float i = 0; i <= 100; i+= 0.1) {
        
        if (ceil(ceil(i/2)/2) == ceil(i/4)) {
            std::cout << "True" << std::endl;
        } else {
            std::cout << "False" << std::endl;
        }
    }
}