#include <stdio.h>
#include <ctype.h>

int main(void) {
    /* Тип int обязателен для корректного распознавания EOF (-1) */
    int ch;

    /* Считываем посимвольно до получения сигнала конца файла (Ctrl+D в Linux) */
    while ((ch = getchar()) != EOF) {
        /* 
         * Приводим ch к unsigned char перед передачей в toupper, 
         * чтобы избежать неопределенного поведения при вводе отрицательных 
         * значений char (например, символов кириллицы в UTF-8).
         */
        putchar(toupper((unsigned char)ch));
    }

    return 0;
}
