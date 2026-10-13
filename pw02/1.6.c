#include <stdio.h>
#include <stdint.h>

int main(void) {
    uint8_t val;    

    if (scanf("%hhu", &val) == 1) {
        uint8_t res_add = val + val;
        uint8_t res_mul = val * 2;
        uint8_t res_sqr = val * val;

        printf("ADD: %u\n", (unsigned int)res_add);
        printf("MUL2: %u\n", (unsigned int)res_mul);
        printf("SQR: %u\n", (unsigned int)res_sqr);
    }

    return 0;
}
