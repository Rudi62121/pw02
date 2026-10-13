#include <stdio.h>
#include <float.h>

int main(void) {
    printf("FLOAT: size=%d, digits=%d, max=%e\n",
        (int)sizeof(float), FLT_DIG, (double)FLT_MAX);

    printf("DOUBLE: size=%d, digits=%d, max=%e\n",
        (int)sizeof(double), DBL_DIG, DBL_MAX);

    printf("LDOUBLE: size=%d, digits=%d, max=%Le\n",
        (int)sizeof(long double), LDBL_DIG, (long double)LDBL_MAX);

    return 0;
}
