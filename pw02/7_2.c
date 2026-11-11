#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void) {
    int ch;
    unsigned long long total_chars = 0;
    unsigned long long words_ending_with_dot = 0;

    bool in_word = false;       /* Флаг нахождения внутри слова */
    bool ends_with_dot = false; /* Флаг, что последний символ слова — точка */

    while ((ch = getchar()) != EOF) {
        total_chars++;
        unsigned char uch = (unsigned char)ch;

        if (isspace(uch)) {
            /* Встретили пробельный символ (пробел, табуляцию, \n) — слово закончилось */
            if (in_word && ends_with_dot) {
                words_ending_with_dot++;
            }
            in_word = false;
            ends_with_dot = false;
        } else {
            /* Любой непробельный символ считается частью слова */
            in_word = true;
            if (uch == '.') {
                ends_with_dot = true;
            } else {
                ends_with_dot = false;
            }
        }
    }

    /* 
     * Защита на случай, если пользователь нажал Ctrl+D (EOF) 
     * сразу после слова с точкой, не нажав перед этим пробел или Enter.
     */
    if (in_word && ends_with_dot) {
        words_ending_with_dot++;
    }

    printf("\nОбщее количество обработанных символов: %llu\n", total_chars);
    printf("Количество слов, заканчивающихся на точку: %llu\n", words_ending_with_dot);

    return 0;
}
