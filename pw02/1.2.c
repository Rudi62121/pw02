#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int main2(void) {
    int num1, num2;
    if (scanf("%d %d", &num1, &num2) == 2) {
        bool flag1 = num1;
        bool flag2 = num2;

        printf("MODULE READY: %d\n", flag1);
        printf("FAULT STATE: %d\n", flag2);
        printf("BOOL SIZE: %d\n", (int)sizeof(bool));
        printf("FLAGS SUM: %d\n", (int)(flag1 + flag2));
    }

    // Любое ненулевое значение преобразуется в 1, потому что согласно стандарту Си 
    // при приведении к типу bool (или _Bool) 0 преобразуется в false (0), 
    // а любое значение, не равное нулю, строго нормализуется до true (1).

    return 0;
}
