#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>

int main4(void) {
    printf("INT MIN: %d\n", INT_MIN);
    printf("INT MAX: %d\n", INT_MAX);
    printf("UINT MAX: %u\n", UINT_MAX);

    // Проверка диапазона
    int range_ok = ((unsigned int)INT_MAX * 2u + 1u == UINT_MAX);
    printf("RANGE OK: %d\n", range_ok);

    /*
       ПОЯСНЕНИЕ:
       Приведение к беззнаковому типу (unsigned int) необходимо для предотвращения
       знакового переполнения (signed overflow), которое по стандарту Си является
       неопределенным поведением (Undefined Behavior). Беззнаковое же переполнение
       строго регламентировано и подчиняется законам модульной арифметики.
    */

    return 0;
}
