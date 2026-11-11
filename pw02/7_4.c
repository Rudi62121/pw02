#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/* 
 * Функция принимает указатели на две переменные типа double
 * и возводит их значения в квадрат напрямую в памяти.
 */
void square_both(double *ptr_a, double *ptr_b) {
    /* Защита от передачи нулевого указателя (NULL) */
    if (ptr_a == NULL || ptr_b == NULL) {
        return;
    }

    *ptr_a = (*ptr_a) * (*ptr_a);
    *ptr_b = (*ptr_b) * (*ptr_b);
}

/* Вспомогательная функция очистки буфера до конца строки или EOF */
bool clear_buffer(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        continue;
    }
    return (ch != EOF);
}

int main(void) {
    double x = 0.0, y = 0.0;
    int status;

    printf("Введите два числа (или Ctrl+D для выхода):\n");

    while (true) {
        printf("> ");
        status = scanf("%lf %lf", &x, &y);

        if (status == EOF) {
            printf("\nПолучен сигнал конца ввода (EOF). Завершение программы.\n");
            break;
        }

        if (status != 2) {
            printf("Ошибка: введите два корректных числа.\n");
            if (!clear_buffer()) {
                printf("\nПолучен сигнал конца ввода (EOF). Завершение программы.\n");
                break;
            }
            continue;
        }

        if (!isfinite(x) || !isfinite(y)) {
            printf("Ошибка: введите конечные числовые значения.\n");
            clear_buffer();
            continue;
        }

        /* Проверка на отсутствие лишних символов после второго числа */
        int ch;
        bool has_extra = false;
        while ((ch = getchar()) != '\n' && ch != EOF) {
            if (ch != ' ' && ch != '\t' && ch != '\r') {
                has_extra = true;
            }
        }

        if (has_extra) {
            printf("Ошибка: введены лишние символы после чисел. Повторите попытку.\n");
            if (ch == EOF) {
                break;
            }
            continue;
        }

        printf("Исходные значения:   x = %.4f, y = %.4f\n", x, y);

        /* Передаем адреса переменных с помощью унарного оператора '&' */
        square_both(&x, &y);

        printf("Измененные значения: x = %.4f, y = %.4f\n", x, y);

        if (ch == EOF) {
            printf("\nПолучен сигнал конца ввода (EOF). Завершение программы.\n");
            break;
        }
    }

    return 0;
}
