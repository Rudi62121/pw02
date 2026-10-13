#include <stdio.h>

int main(void) {
    int dec = 10;
    int oct = 010;
    int hex = 0x10;

    printf("DEC 10: %d\n", dec);
    printf("OCT 10: %d\n", oct);
    printf("HEX 10: %d\n", hex);

    printf("INT SUFFIX: %d %d %d %d\n",
        (int)sizeof(10), (int)sizeof(10u), (int)sizeof(10LL), (int)sizeof(10ULL));

    printf("SUFFIX FLOAT: %d %d %d\n",
        (int)sizeof(0.1f), (int)sizeof(0.1), (int)sizeof(0.1L));

    printf("EQ: %d\n", 0.1f == 0.1);

    char ch = 'A';
    printf("CHAR FORMS: %d %d %d\n", 'A', '\x41', '\101');
    printf("LIT VAR STR: %d %d %d\n", (int)sizeof('A'), (int)sizeof(ch), (int)sizeof("A"));

    return 0;
}
