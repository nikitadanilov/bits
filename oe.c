/* https://people.eecs.berkeley.edu/~wkahan/Mindless.pdf, p. 14. */
#include <stdio.h>

double Œ(double y, double z){
    return 108.0 - (815.0 - 1500.0 / z) / y;
}

int main(int argc, char **argv)
{
    double a = 4.0;
    double b = 4.25;
    for (int i = 2; i <= 80; ++i) {
        double c = Œ(a, b);
        a = b;
        b = c;
        printf("%2i %f\n", i, b);
    }
}
