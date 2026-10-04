#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main1(void) {
    int dec_val, hex_val, oct_val;

    // Считываем 10-ичную, 16-ичную и 8-ичную записи
    if (scanf("%d %x %o", &dec_val, &hex_val, &oct_val) == 3) {
        int sum = dec_val + hex_val + oct_val;

        printf("UNIT_ID: %d\n", dec_val);
        printf("UNIT_VERSION: %d\n", hex_val);
        printf("UNIT_STATUS: %d\n", oct_val);
        printf("SUM: %d\n", sum);
    }

    return 0;
}