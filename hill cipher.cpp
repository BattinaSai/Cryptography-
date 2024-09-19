#include <stdio.h>
#include <math.h>
double log2Factorial(int n) {
    if (n == 0 || n == 1) return 0.0;
    double stirlingApprox = 0.5 * log(2 * M_PI * n) + n * log(n / M_E);
    return stirlingApprox / log(2); 
}

int main() {
    int n = 25; 
    double log2Keys = log2Factorial(n);
    printf("Approximate log2 of possible keys for Playfair cipher: %.2f\n", log2Keys);
    printf("Approximate number of possible keys: 2^%.2f\n", log2Keys);
    return 0;
}

