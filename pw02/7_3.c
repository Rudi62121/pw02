#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/* 
 * Функция вычисляет произведение всех целых чисел строго между a и b.
 * Если целых чисел между ними нет, возвращается 0.0.
 */
double product_between(double a, double b) {
    /* Определяем меньшую и большую границы */
    double min_val = (a < b) ? a : b;
    double max_val = (a > b) ? a : b;

    /* 
     * Находим первое целое число строго больше min_val 
     * и последнее целое число строго меньше max_val.
     */
    long long start = (long long)floor(min_val) + 1;
    long long end = (long long)ceil(max_val) - 1;

    /* Если между числами нет ни одного целого (например, 2.1 и 2.9 или 3 и 4) */
    if (start > end) {
        return 0.0;
    }

    /* 
     * Если в диапазон попадает 0, произведение гарантированно равно 0.
     * Это также защищает от лишних итераций на огромных диапазонах (например, -1e9 и 1e9).
     */
    if (start <= 0 && end >= 0) {
        return 0.0;
    }

    double result = 1.0;
    for (long long i = start; i <= end; i++) {
        result *= (double)i;
        /* Прерываем цикл при достижении бесконечности, чтобы не тратить время процессора */
        if (isinf(result)) {
            break;
        }
    }

    return result;
}

/* Вспомогательная функция для очистки буфера ввода до конца строки или EOF */
bool clear_input_buffer(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        continue;
    }
    return (ch != EOF);
}

int main(void) {
    double a, b;
    int status;

    printf("Введите два вещественных числа (или Ctrl+D для выхода):\n");

    while (true) {
        printf("> ");
        status = scanf("%lf %lf", &a, &b);

        if (status == EOF) {
            /* Пользователь нажал Ctrl+D или закончился входной файл */
            printf("\nОбнаружен конец ввода (EOF). Завершение работы.\n");
            break;
        }

        if (status != 2) {
            /* Введены нечисловые данные (например, буквы) */
            printf("Ошибка ввода: необходимо ввести два числа.\n");
            if (!clear_input_buffer()) {
                printf("\nОбнаружен конец ввода (EOF). Завершение работы.\n");
                break;
            }
            continue;
        }

        /* Проверка на некорректные значения стандарта IEEE 754 (NaN, Inf) */
        if (!isfinite(a) || !isfinite(b)) {
            printf("Ошибка: введите конечные числовые значения.\n");
            clear_input_buffer();
            continue;
        }

        /* 
         * Проверка на "хвост" в строке ввода: например, если ввели "2 5 abc".
         * Отбрасываем пробелы до конца строки и проверяем, нет ли лишних символов.
         */
        int extra_ch;
        bool has_garbage = false;
        while ((extra_ch = getchar()) != '\n' && extra_ch != EOF) {
            if (extra_ch != ' ' && extra_ch != '\t' && extra_ch != '\r') {
                has_garbage = true;
            }
        }

        if (has_garbage) {
            printf("Ошибка ввода: обнаружены лишние символы после чисел. Повторите ввод.\n");
            if (extra_ch == EOF) {
                break;
            }
            continue;
        }

        double res = product_between(a, b);
        printf("Результат: %.4f\n", res);

        if (extra_ch == EOF) {
            printf("\nОбнаружен конец ввода (EOF). Завершение работы.\n");
            break;
        }
    }

    return 0;
}
