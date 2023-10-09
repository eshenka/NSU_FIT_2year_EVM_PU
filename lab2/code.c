#include <stdio.h>
#include <time.h> 

double Power(double number, double pow) {
    double result = 1;
    for (int i = 1; i <= pow; i++) {
        result *= number;
    }
    return result;
}

int main() {
    struct timespec start, end;

    double n = 110000;
    double x = 0.5;
    double sum = 0;
    
    for (n; n <= 120000; n += 10000) {
        for (int j = 0; j < 3; j++) {
            clock_gettime(CLOCK_MONOTONIC_RAW, &start);
            for (double i = 1; i <= n; i++) {
                sum += (Power(-1, i + 1) * Power(x, i) / i);
            }
            clock_gettime(CLOCK_MONOTONIC_RAW, &end);
            printf("Time taken: %lf sec.\n", end.tv_sec-start.tv_sec + 0.000000001*(end.tv_nsec-start.tv_nsec));
        }
    }
    
    printf("%f\n", sum);

    return 0;
}