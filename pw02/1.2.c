#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int num1, num2;
    if (scanf("%d %d", &num1, &num2) == 2) {
        bool flag1 = num1;
        bool flag2 = num2;

        printf("MODULE READY: %d\n", flag1);
        printf("FAULT STATE: %d\n", flag2);
        printf("BOOL SIZE: %d\n", (int)sizeof(bool));
        printf("FLAGS SUM: %d\n", (int)(flag1 + flag2));
    }

    return 0;
}
