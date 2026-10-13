#include <stdio.h>
#include <limits.h>

int main(void) {
    printf("INT MIN: %d\n", INT_MIN);
    printf("INT MAX: %d\n", INT_MAX);
    printf("UINT MAX: %u\n", UINT_MAX);

    int range_ok = ((unsigned int)INT_MAX * 2u + 1u == UINT_MAX);
    printf("RANGE OK: %d\n", range_ok);

    return 0;
}
