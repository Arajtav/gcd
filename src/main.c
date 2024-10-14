#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char** argv) {
    if (argc != 3) {
        puts("you need to have 2 args");
        return 1;
    }
    double a = atof(argv[1]);
    double b = atof(argv[2]);

    int kill = 0;
    while (b > 0) {
        double tmp = b;
        b = fmod(a, b);
        a = tmp;
        if (kill++ == INT32_MAX) {
            puts("failed to compute in reasonable number of iterations");
            return 2;
        }
    }
    printf("%lf\n", a);
}
