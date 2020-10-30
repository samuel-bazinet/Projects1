#include<iostream>
#include"stats.h"

using namespace std;

int main() {

    int count = 1;
    int got;
    int g0 = 0;
    int g1 = 0;
    int g2 = 0;
    int g3 = 0;
    int g4 = 0;

    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            if (j == i) 
                continue;
            for (int k = 1; k <= 4; k++) {
                if (k == j || k == i) {
                    continue;
                }
                for (int l = 1; l <= 4; l++) {
                    if (l == k || l == j || l == i)
                        continue;

                    got = 0;

                    if (i == 1) {got++;}
                    if (j == 2) {got++;}
                    if (k == 3) {got++;}
                    if (l == 4) {got++;}

                    switch (got) {
                        case (0):
                            g0++;
                            break;
                        case (1):
                            g1++;
                            break;
                        case (2):
                            g2++;
                            break;
                        case (3):
                            g3++;
                            break;
                        case (4):
                            g4++;
                            break;
                        default:
                            break;
                    }

                    cout << count << ". ( " << i << ", " << j << ", " << k << ", " << l << " ) " << got << endl;
                    count++;

                }
            }
        }
    }

    cout << "0: " << g0 << endl << "1: " << g1 << endl << "2: " << g2 << endl << "3: " << g3 << endl << "4: " << g4 << endl;

    return 0;
}