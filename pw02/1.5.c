#include <stdio.h>
#include <stdint.h>

int main(void) {
    printf("INT8: size=%d, min=%d, max=%d, values=%llu\n",
        (int)sizeof(int8_t), INT8_MIN, INT8_MAX, (unsigned long long)(INT8_MAX - INT8_MIN) + 1);
    printf("UINT8: size=%d, min=%d, max=%d, values=%llu\n",
        (int)sizeof(uint8_t), 0, UINT8_MAX, (unsigned long long)(UINT8_MAX - 0) + 1);

    printf("INT16: size=%d, min=%d, max=%d, values=%llu\n",
        (int)sizeof(int16_t), INT16_MIN, INT16_MAX, (unsigned long long)(INT16_MAX - INT16_MIN) + 1);
    printf("UINT16: size=%d, min=%d, max=%d, values=%llu\n",
        (int)sizeof(uint16_t), 0, UINT16_MAX, (unsigned long long)(UINT16_MAX - 0) + 1);

    printf("INT32: size=%d, min=%d, max=%d, values=%llu\n",
        (int)sizeof(int32_t), INT32_MIN, INT32_MAX, (unsigned long long)(INT32_MAX - INT32_MIN) + 1);
    printf("UINT32: size=%d, min=%d, max=%d, values=%llu\n",
        (int)sizeof(uint32_t), 0, UINT32_MAX, (unsigned long long)(UINT32_MAX - 0) + 1);

    return 0;
}
