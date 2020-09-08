#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int power(int n, int x);
void buffer_to_int(char *buffer, int *ptr);
void int_to_buffer(char *buffer, int num);

void __strcpy(char *dest, char *src1, char *src2) {
    for (int i = 0; i < 4; i++) {
        dest[i] = src1[i];
    }
    for (int i = 0; i < 4; i++) {
        dest[4 + i] = src2[i];
    }
    dest[8] = '\0';
}

int main(void) {
    int A, B;
    char buffer[9];
    char buffer2[5], buffer3[5];
    char operator[10];
    memset(operator, 0, 10);

    printf("2진수와 연산자를 입력 하시오.\n");

    printf("A: ");
    scanf("%4s %4s", buffer2, buffer3);
    __strcpy(buffer, buffer2, buffer3);
    buffer_to_int(buffer, &A);

    printf("B: ");
    scanf("%4s %4s", buffer2, buffer3);
    __strcpy(buffer, buffer2, buffer3);
    buffer_to_int(buffer, &B);

    int result;
    int resCode = 0;
    do {
        printf("연산자: ");
        scanf("%4s", operator);
        resCode = 0;
        if (!strcmp(operator, "AND")) {
            result = A & B;
        } else if (!strcmp(operator, "OR")) {
            result = A | B;
        } else if (!strcmp(operator, "NOT")) {
            result = ~A;
        } else if (!strcmp(operator, "NAND")) {
            result = ~(A & B);
        } else if (!strcmp(operator, "NOR")) {
            result = ~(A | B);
        } else if (!strcmp(operator, "XOR")) {
            result = A ^ B;
        } else {
            printf("잘못된 연산자입니다.\n");
            resCode = 1;
        }
    } while (resCode);

    char result_buffer[9];
    char print_buffer[5];
    int_to_buffer(result_buffer, result);
    if (!strcmp(operator, "NOT")) {
        printf("NOT A");
    } else {
        printf("A %s B", operator);
    }

    printf(" = ");
    for (int i = 0; i < 2; i++) {
        strncpy(print_buffer, result_buffer + 4 * i, 4);
        printf("%4s ", print_buffer);
    }
    printf("\n");

    return 0;
}

int power(int n, int x) {
    if (x <= 0) {
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

void buffer_to_int(char *buffer, int *ptr) {
    *ptr = 0;
    for (int i = 7; i >= 0; i--) {
        if (buffer[i] == '1') {
            *ptr += power(2, 7 - i);
        }
    }
}

void int_to_buffer(char *buffer, int num) {
    memset(buffer, '0', 8);
    buffer[8] = '\0';
    for (int i = 7; i >= 0; i--) {
        const int checker = (1 << i);
        if (num & checker) {
            buffer[7 - i] = '1';
        }
    }
}