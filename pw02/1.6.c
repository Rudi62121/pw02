#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>

int main6(void) {
    uint8_t val;    

    if (scanf("%hhu", &val) == 1) {
        uint8_t res_add = val + val; // или любая сумма по контексту задачи
        uint8_t res_mul = val * 2;
        uint8_t res_sqr = val * val;

        printf("ADD: %u\n", (unsigned int)res_add);
        printf("MUL2: %u\n", (unsigned int)res_mul);
        printf("SQR: %u\n", (unsigned int)res_sqr);
    }

    // Результаты "сворачиваются" по модулю 256, потому что тип uint8_t занимает 
    // ровно 8 бит. Любые биты результата, вышедшие за пределы 8-го бита (старшие биты), 
    // аппаратно отбрасываются процессором. Математически это эквивалентно взятию остатка от деления на 2^8 (256).

    return 0;
}
