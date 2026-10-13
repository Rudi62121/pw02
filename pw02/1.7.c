#include <stdio.h>

int main(void) {
    long double ld_val;

    if (scanf("%Lf", &ld_val) == 1) {
        double d_val = (double)ld_val;
        float f_val = (float)ld_val;

        printf("FLOAT: %.6f\n", (double)f_val);
        printf("DOUBLE: %.6f\n", d_val);
        printf("LDOUBLE: %.6Lf\n", ld_val);

        printf("FLOAT+1: %.6f\n", (double)(f_val + 1.0f));
        printf("DOUBLE+1: %.6f\n", d_val + 1.0);
        printf("LDOUBLE+1: %.6Lf\n", ld_val + 1.0L);
    }

    return 0;
}
