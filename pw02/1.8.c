#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <float.h>

int main8(void) {
    printf("FLOAT: size=%d, digits=%d, max=%e\n",
        (int)sizeof(float), FLT_DIG, (double)FLT_MAX);

    printf("DOUBLE: size=%d, digits=%d, max=%e\n",
        (int)sizeof(double), DBL_DIG, DBL_MAX);

    // Особенность компилятора MSVC: long double эквивалентен double
    printf("LDOUBLE: size=%d, digits=%d, max=%Le\n",
        (int)sizeof(long double), LDBL_DIG, (long double)LDBL_MAX);

    // Внимание: В MSVC размер long double равен 8 байтам (совпадает с double), 
    // в отличие от GCC/MinGW, где он может занимать 12 или 16 байт.

    return 0;
}
