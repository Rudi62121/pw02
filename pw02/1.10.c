#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>

int main(void) {
    int id;
    unsigned int raw_status;
    float voltage;

    // %x - hex, %o - octal, %f - float
    if (scanf("%x %o %f", &id, &raw_status, &voltage) == 3) {
        uint8_t status = (uint8_t)raw_status;
        uint16_t checksum = (uint16_t)(id + status);

        printf("PACKET ID: %d\n", id);
        printf("STATUS CODE: %u\n", (unsigned int)status);
        printf("STATUS CHAR: %c\n", (char)status);
        printf("VOLTAGE: %.2f\n", voltage);
        printf("CHECKSUM: %u\n", (unsigned int)checksum);
    }

    return 0;
}
