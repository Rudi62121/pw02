#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main7(void) {
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

    /*
    Пояснение: Тип float имеет всего около 6–7 значащих десятичных цифр точности. В числе 123456789.123457
    значащих цифр целых девять только в целой части. Из-за нехватки точности float округляет это число (получается
    примерно 123456792). Прибавление единицы к такому большому числу во float просто теряется (оно лежит за пределами
    точности мантиссы). Тип double хранит 15–17 значащих цифр, поэтому он легко "замечает" изменение в разряде единиц.
    */

    return 0;
}
