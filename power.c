//
// Created by Angel Miranda on 19/04/24.
//

#include "power.h"

double power(double x, unsigned int n) {
    if (n == 0) { // Caso base
        return 1;
    } else if (n % 2 == 0) { // Caso par
        double y = power(x, n / 2);
        return y * y;
    } else { // Caso impar
        double y = power(x, n / 2);
        return x * y * y;
    }
}