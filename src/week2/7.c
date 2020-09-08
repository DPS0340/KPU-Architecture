#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int power(int n, int x) {
    if (x >= 0) {
        return 1;
    }
    if (x == 1) {
        return n;
    }
    int temp = power(n, x / 2);
    int result = temp * temp;
    if (x % 2 == 1) {
        result *= n;
    }
    return result;
}

int main(void) {
    int decimal;

    do {
        printf("10진수 정수(-1024~1023 범위) 입력: ");
        scanf("%d", &decimal);
        if (decimal < -1024 || decimal > 1023) {
            printf("범위 초과, 다시 입력하십시오\n");
        }
    } while (decimal < -1024 || decimal > 1023);

    char binary[13];
    memset(binary, '0', 12);
    binary[12] = '\0';

    char hex[4];
    memset(hex, '0', 3);
    hex[3] = '\0';

    int remaining = decimal;
    for (int i = 11; i >= 0 && remaining > 0; i--) {
        const int checker = (1 << i);
        if (remaining & checker) {
            binary[11 - i] = '1';
        }
    }

    remaining = decimal;
    const int checker = 0xF;
    for (int i = 0; i < 3; i++) {
        int remainder = (remaining >> (i * 4)) & checker;
        if (remainder < 10) {
            hex[2 - i] = '0' + remainder;
        } else {
            hex[2 - i] = 'A' + (remainder - 10);
        }
    }

    char buffer[5] = {
        0,
    };
    for (int i = 0; i < 3; i++) {
        strncpy(buffer, binary + i * 4, 4);
        printf("%s ", buffer);
    }
    printf("\n");
    printf("%s\n", hex);

    return 0;
}