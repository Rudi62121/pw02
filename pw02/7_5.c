#include <stdio.h>
#include <stdbool.h>

/* 
 * Максимальное N для рекурсивной версии.
 * При N > 16 двойная рекурсия (сложность O(4^N / N^1.5)) 
 * начинает работать слишком медленно (более нескольких секунд).
 */
#define MAX_REC_N 16

/* 
 * Максимальное N для итеративной версии, при котором C_n 
 * помещается в 64-битный беззнаковый тип unsigned long long:
 * C_35 = 3 116 285 494 907 301 262 (помещается в ULLONG_MAX),
 * C_36 уже вызывает переполнение.
 */
#define MAX_ITER_N 35

/* 1. Рекурсивное вычисление числа Каталана по формуле Сегнера:
 * C_0 = 1
 * C_n = сумма (C_i * C_{n - 1 - i}) для i от 0 до n - 1
 */
unsigned long long catalan_recursive(unsigned int n) {
    if (n <= 1) {
        return 1ULL;
    }

    unsigned long long res = 0ULL;
    for (unsigned int i = 0; i < n; i++) {
        res += catalan_recursive(i) * catalan_recursive(n - 1 - i);
    }
    return res;
}

/* 2. Итеративное вычисление числа Каталана через рекуррентное соотношение:
 * C_0 = 1
 * C_i = C_{i-1} * 2 * (2*i - 1) / (i + 1)
 * Деление выполняется на каждом шаге без остатка, что снижает риск переполнения.
 */
unsigned long long catalan_iterative(unsigned int n) {
    if (n <= 1) {
        return 1ULL;
    }

    unsigned long long c = 1ULL;
    for (unsigned int i = 1; i <= n; i++) {
        /* 
         * Разделяем умножение и деление через НОД или порядок операций,
         * чтобы промежуточное произведение не вышло за пределы unsigned long long при n <= 35.
         */
        unsigned long long num = 2ULL * (2ULL * i - 1ULL);
        unsigned long long den = i + 1ULL;

        /* Находим НОД(c, den), чтобы сократить дробь до умножения */
        unsigned long long a = c, b = den;
        while (b != 0) {
            unsigned long long temp = b;
            b = a % b;
            a = temp;
        }
        unsigned long long gcd = a;

        c = (c / gcd) * (num / (den / gcd));
    }
    return c;
}

/* Очистка буфера до конца строки или EOF */
bool clear_buffer(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        continue;
    }
    return (ch != EOF);
}

int main(void) {
    long long input_n;
    int status;

    printf("Вычисление N-го числа Каталана (N >= 0).\n");
    printf("Для корректного сравнения обоих методов введите N от 0 до %d (или Ctrl+D для выхода):\n", MAX_REC_N);

    while (true) {
        printf("> ");
        status = scanf("%lld", &input_n);

        if (status == EOF) {
            printf("\nОбнаружен конец ввода (EOF). Завершение работы.\n");
            break;
        }

        if (status != 1) {
            printf("Ошибка ввода: введите целое неотрицательное число.\n");
            if (!clear_buffer()) {
                printf("\nОбнаружен конец ввода (EOF). Завершение работы.\n");
                break;
            }
            continue;
        }

        /* Проверка на отсутствие "хвоста" после числа (например, "5abc" или "5.5") */
        int ch;
        bool has_extra = false;
        while ((ch = getchar()) != '\n' && ch != EOF) {
            if (ch != ' ' && ch != '\t' && ch != '\r') {
                has_extra = true;
            }
        }

        if (has_extra) {
            printf("Ошибка ввода: обнаружены лишние символы или дробная часть. Введите целое число.\n");
            if (ch == EOF) {
                break;
            }
            continue;
        }

        /* Проверка диапазона допустимых значений */
        if (input_n < 0) {
            printf("Ошибка: номер числа Каталана не может быть отрицательным (N >= 0).\n");
            if (ch == EOF) break;
            continue;
        }

        if (input_n > MAX_ITER_N) {
            printf("Ошибка: при N > %d результат превышает максимальное значение типа unsigned long long.\n", MAX_ITER_N);
            if (ch == EOF) break;
            continue;
        }

        unsigned int n = (unsigned int)input_n;
        unsigned long long iter_res = catalan_iterative(n);
        printf("Итеративный метод (C_%u): %llu\n", n, iter_res);

        if (n <= MAX_REC_N) {
            unsigned long long rec_res = catalan_recursive(n);
            printf("Рекурсивный метод (C_%u): %llu\n", n, rec_res);
        } else {
            printf("Рекурсивный метод: пропущен для N > %d во избежание зависания (экспоненциальный рост вызовов).\n", MAX_REC_N);
        }

        if (ch == EOF) {
            printf("\nОбнаружен конец ввода (EOF). Завершение работы.\n");
            break;
        }
    }

    return 0;
}
